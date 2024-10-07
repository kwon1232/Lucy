// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct  FLucyInputActionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;

	bool IsValid() const
	{
		return InputTag.IsValid() && InputAction;
	}
};


/**
 * 
 */
UCLASS()
class LUCY_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitileProperty = "InputAction"))
	TArray<FLucyInputActionConfig> NativeInputActions;

	TObjectPtr<UInputAction> FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitileProperty = "InputAction"))
	TArray<FLucyInputActionConfig> AbilityInputActions;
};
