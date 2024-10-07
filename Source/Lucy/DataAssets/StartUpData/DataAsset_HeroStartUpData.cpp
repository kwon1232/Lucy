// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "Lucy/AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "Lucy/AbilitySystem/WarriorAbilitySystemComponent.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

    for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
    {
        if (AbilitySet.IsValid()) continue;
        
        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

        InASCToGive->GiveAbility(AbilitySpec);
    }
}
