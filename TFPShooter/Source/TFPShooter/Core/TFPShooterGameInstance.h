// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Components/SkeletalMeshComponent.h"
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
		USkeletalMeshComponent* faceMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* LegsMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* HandsMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* ChestMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* eyebrowMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* eyesMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* hairMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* beardMesh;
		
};
