// Fill out your copyright notice in the Description page of Project Settings.


#include "TFPShooterGameInstance.h"

UTFPShooterGameInstance::UTFPShooterGameInstance()
{
	UE_LOG(LogTemp, Warning, TEXT("Initialise Game Instance"));
}

USkeletalMesh* UTFPShooterGameInstance::GetCharSkeletalMesh()
{
	return charSkeletalMesh;
}

void UTFPShooterGameInstance::SetCharSkeletalMesh(USkeletalMesh* _charSkeletalMesh)
{
	charSkeletalMesh = _charSkeletalMesh;
}

UMaterialInterface* UTFPShooterGameInstance::GetCharMaterialInstance()
{
	return charMaterialInstance;
}

void UTFPShooterGameInstance::SetCharMaterialInstance(UMaterialInterface* _charMaterialInstance)
{
	charMaterialInstance = _charMaterialInstance;
}
