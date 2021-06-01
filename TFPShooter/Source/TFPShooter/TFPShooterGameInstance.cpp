// Fill out your copyright notice in the Description page of Project Settings.


#include "TFPShooterGameInstance.h"

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
