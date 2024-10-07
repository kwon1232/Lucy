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
		// ���� �±׿� ���� �±װ� �ƴ϶�� �ǳʶڴ�.
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) {

			Debug::Print(TEXT("4"));
			continue;
		}
		// ���� ���� �±׿� ���ٸ� Ability�� Ȱ��ȭ ��Ų��.
		TryActivateAbility(AbilitySpec.Handle);

		Debug::Print(TEXT("3"));
	}
}

void UWarriorAbilitySystemComponent::OnAbliltyInputReleased(const FGameplayTag& InInputTag)
{
}
