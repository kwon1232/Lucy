// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lucy/AnimInstances/LucyBaseAnimInstance.h"
#include "WorriorAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LUCY_API UWorriorAnimInstance : public ULucyBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
};
