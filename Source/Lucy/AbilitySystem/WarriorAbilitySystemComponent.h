// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class LUCY_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbliltyInputPressed(const FGameplayTag& InInputTag);
	void OnAbliltyInputReleased(const FGameplayTag& InInputTag);
};
