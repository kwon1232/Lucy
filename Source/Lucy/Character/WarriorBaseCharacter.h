// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lucy/Character/LucyBaseCharacter.h"
#include "AbilitySystemInterface.h"
#include "WarriorBaseCharacter.generated.h"

/**
 * 
 */

class UWarriorAbilitySystemComponent;
class UWarriorAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class LUCY_API AWarriorBaseCharacter : public ALucyBaseCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AWarriorBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorAbilitySystemComponent> WarriorAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorAttributeSet> WarriorAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE TObjectPtr<UWarriorAbilitySystemComponent> GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent.Get(); }
	FORCEINLINE TObjectPtr<UWarriorAttributeSet> GetWarriorAttributeSet() const { return WarriorAttributeSet.Get(); }
};
