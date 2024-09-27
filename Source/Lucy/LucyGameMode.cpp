// Copyright Epic Games, Inc. All Rights Reserved.

#include "LucyGameMode.h"
#include "LucyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALucyGameMode::ALucyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
