// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/AnimInstances/LucyBaseAnimInstance.h"

#include "Lucy/Character/LucyBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void ULucyBaseAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ALucyBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningCharacterMovementComponent = OwningCharacter->GetCharacterMovement();
	}

}

void ULucyBaseAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningCharacterMovementComponent)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningCharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
}
