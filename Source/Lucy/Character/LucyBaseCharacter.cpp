// Fill out your copyright notice in the Description page of Project Settings.


#include "Lucy/Character/LucyBaseCharacter.h"

// Sets default values
ALucyBaseCharacter::ALucyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}
