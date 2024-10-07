// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lucy/Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;
/**
 * 
 */
UCLASS()
class LUCY_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	// 등록된 무기 탐색할 수 있음
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	// 캐릭터가 사용할 특정 무기를 검색할 수 있음 
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	// 현재 장착된 무기를 추적하는 데 사용하는 태그 
	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	// 현재 가지고 있는 무기 가저오는 함수
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;


private:
	// TMap으로 쉽게 회수할 수 있는 여러개의 무기를 저장할 수 있음
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
