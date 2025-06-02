// Fill out your copyright notice in the Description page of Project Settings.

#include "Lucy/DataAssets/Input/DataAsset_InputConfig.h"

#include "InputMappingContext.h"
#include "InputAction.h"


UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FLucyInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}

	return nullptr;
}