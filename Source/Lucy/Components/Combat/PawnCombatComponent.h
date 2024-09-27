// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lucy/Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorBaseCharacter;
/**
 * 
 */
UCLASS()
class LUCY_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	// ��ϵ� ���� Ž���� �� ����
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorBaseCharacter* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	// ĳ���Ͱ� ����� Ư�� ���⸦ �˻��� �� ���� 
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorBaseCharacter* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	// ���� ������ ���⸦ �����ϴ� �� ����ϴ� �±� 
	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	// ���� ������ �ִ� ���� �������� �Լ�
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorBaseCharacter* GetCharacterCurrentEquippedWeapon() const;


private:
	// TMap���� ���� ȸ���� �� �ִ� �������� ���⸦ ������ �� ����
	TMap<FGameplayTag, AWarriorBaseCharacter*> CharacterCarriedWeaponMap;
};
