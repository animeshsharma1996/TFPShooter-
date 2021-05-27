// Copyright Epic Games, Inc. All Rights Reserved.

#include "TFPShooterGameMode.h"
#include "TFPShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATFPShooterGameMode::ATFPShooterGameMode()
{
	//PrimaryActorTick.bCanEverTick = false;
	//PrimaryActorTick.bStartWithTickEnabled = false;
	//PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/StylizedModularChar/Blueprints/BP_StylizedModularCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
