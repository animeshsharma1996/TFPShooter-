// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/SkeletalMesh.h"
#include "Materials/MaterialInstance.h"
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
	USkeletalMesh* GetCharSkeletalMesh();
	void SetCharSkeletalMesh(USkeletalMesh* _charSkeletalMesh);
	UMaterialInterface* GetCharMaterialInstance();
	void SetCharMaterialInstance(UMaterialInterface* _charMaterialInstance);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMesh* charSkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface* charMaterialInstance;
};
