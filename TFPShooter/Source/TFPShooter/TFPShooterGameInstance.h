// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TFPShooterCharacter.h"
#include "TFPShooterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TFPSHOOTER_API UTFPShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public :
	UTFPShooterGameInstance(); 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ATFPShooterCharacter> BP_SMC;
};
