// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/Components/Combat/PawnCombatComponent.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorBaseCharacter* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
}

AWarriorBaseCharacter* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	return nullptr;
}

AWarriorBaseCharacter* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	return nullptr;
}
