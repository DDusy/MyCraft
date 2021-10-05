// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyCraftGameMode.h"
#include "MyCraftHUD.h"
#include "MyCraftCharacter.h"

#include "MyCraft/MyCraft_Utility.h"
#include "UObject/ConstructorHelpers.h"


AMyCraftGameMode::AMyCraftGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMyCraftHUD::StaticClass();
}

void AMyCraftGameMode::BeginPlay()
{

	//UE_LOG(DDusy, Warning, TEXT("¿ìÈ÷È÷"));
}
