// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/Character/HeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Lucy/DataAssets/Input/DataAsset_InputConfig.h"
#include "Lucy/Components/Input/LucyInputComponent.h"
#include "Lucy/LucyGameplayTags.h"
#include "Lucy/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Lucy/DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "Lucy/Components/Combat/HeroCombatComponent.h"

#include "Lucy/LucyDebugHelper.h"

AHeroCharacter::AHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
}

void AHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
		}
	}
}

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a vaild data asset as input config"));
	TObjectPtr<ULocalPlayer> LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	
	TObjectPtr <UEnhancedInputLocalPlayerSubsystem> Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	
	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	// 캐스트 가능한지 유효성 체크
	// 이 라인을 통과한다면 유효한 inputComponent라는 것 아니라면 null을 반환하기 때문
	TObjectPtr<ULucyInputComponent> LucyInputComponent = CastChecked<ULucyInputComponent>(PlayerInputComponent);

	LucyInputComponent->BindNativeInputAction(InputConfigDataAsset, LucyGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	LucyInputComponent->BindNativeInputAction(InputConfigDataAsset, LucyGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	
	LucyInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}

void AHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	Debug::Print(TEXT("8"));
	WarriorAbilitySystemComponent->OnAbliltyInputPressed(InInputTag);
}

void AHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	Debug::Print(TEXT("9"));
	WarriorAbilitySystemComponent->OnAbliltyInputReleased(InInputTag);
}
