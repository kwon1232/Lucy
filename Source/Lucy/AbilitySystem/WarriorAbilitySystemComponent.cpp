// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/AbilitySystem/WarriorAbilitySystemComponent.h"

#include "Lucy/LucyDebugHelper.h"

void UWarriorAbilitySystemComponent::OnAbliltyInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		Debug::Print(TEXT("5"));
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		Debug::Print(TEXT("1"));
		// 현재 태그와 같은 태그가 아니라면 건너뛴다.
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) {

			Debug::Print(TEXT("4"));
			continue;
		}
		// 만약 현재 태그와 같다면 Ability를 활성화 시킨다.
		TryActivateAbility(AbilitySpec.Handle);

		Debug::Print(TEXT("3"));
	}
}

void UWarriorAbilitySystemComponent::OnAbliltyInputReleased(const FGameplayTag& InInputTag)
{
}
