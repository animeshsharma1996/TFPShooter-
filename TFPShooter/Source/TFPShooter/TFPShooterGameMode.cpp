// Copyright Epic Games, Inc. All Rights Reserved.

#include "TFPShooterGameMode.h"
#include "TFPShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATFPShooterGameMode::ATFPShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/StylizedModularChar/Blueprints/BP_StylizedModularCharacter"));
	DefaultPawnClass = NULL;

	/*if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}

