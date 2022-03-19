// Copyright Epic Games, Inc. All Rights Reserved.

#include "CraftsGameMode.h"
#include "CraftsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACraftsGameMode::ACraftsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
