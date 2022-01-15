// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyCraftGameModeBase.h"

#include "MyCharacter.h"

AMyCraftGameModeBase::AMyCraftGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprints/BP_OriginCharacter.BP_OriginCharacter_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}else
		DefaultPawnClass = AMyCharacter::StaticClass();
}

