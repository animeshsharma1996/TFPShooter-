#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TFPShooterSaveGame.generated.h"

UCLASS()
class TFPSHOOTER_API UTFPShooterSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public :
	UFUNCTION()
		void SaveCharacterMeshes(TArray<USkeletalMesh*> skeletalMeshes, TArray<UStaticMesh*> staticMeshes)
		{
			savedSkeletalMeshes = skeletalMeshes;
			savedStaticMeshes = staticMeshes;
		}
	UFUNCTION()
		FString GetSlotName() { return saveSlotName; }
	UFUNCTION()
		TArray<USkeletalMesh*> LoadSkeletalMeshes() {	return savedSkeletalMeshes; }
	UFUNCTION()
		TArray<UStaticMesh*> LoadStaticMeshes() { return savedStaticMeshes; }

private :
	UPROPERTY()
		FString saveSlotName = "SavedCharacterMesh";
	UPROPERTY()
		TArray<USkeletalMesh*> savedSkeletalMeshes;
	UPROPERTY()
		TArray<UStaticMesh*> savedStaticMeshes;
};
