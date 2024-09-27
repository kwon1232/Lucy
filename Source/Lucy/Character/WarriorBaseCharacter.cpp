// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/Character/WarriorBaseCharacter.h"

#include "Lucy/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Lucy/AbilitySystem/WarriorAttributeSet.h"
#include "Lucy/DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));

	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));
	CharacterStartUpData = CreateDefaultSubobject<UDataAsset_StartUpDataBase>(TEXT("CharacterStartUpData"));
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetAbilitySystemComponent();
}

void AWarriorBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forget to assing start up data to %s"), *GetName());
	}

}
