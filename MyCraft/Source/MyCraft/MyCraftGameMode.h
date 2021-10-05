// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyCraftGameMode.generated.h"

UCLASS(minimalapi)
class AMyCraftGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyCraftGameMode();

public:
	virtual void BeginPlay() override;

};



