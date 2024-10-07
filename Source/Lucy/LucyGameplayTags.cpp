// Fill out your copyright notice in the Description page of Project Settings.


#include "LucyGameplayTags.h"

namespace LucyGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipWeapon, "InputTag.EquipWeapon");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipWeapon, "InputTag.UnequipWeapon");
	
	/** Player tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
}