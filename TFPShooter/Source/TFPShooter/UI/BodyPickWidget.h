#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../PlayerCharacter/TFPShooterCharacter.h"
#include "../SaveGame/TFPShooterSaveGame.h"
#include "BodyPickWidget.generated.h"

UCLASS()
class TFPSHOOTER_API UBodyPickWidget : public UUserWidget
{
	GENERATED_BODY()
		virtual bool Initialize() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<UTFPShooterSaveGame> tfpShooterSaveGame;
	UPROPERTY(meta = (BindWidget))
		class UButton* chestLButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* chestRButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* legsLButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* legsRButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* handsLButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* handsRButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* faceButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* genderButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* confirmButton;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* genderButtonText;

private:
	UFUNCTION()
		void OnChestLButtonClicked() { pCharacter->ChestNext(); }
	UFUNCTION()
		void OnChestRButtonClicked() { pCharacter->ChestPrevious(); }
	UFUNCTION()
		void OnLegsLButtonClicked() { pCharacter->LegsNext(); }
	UFUNCTION()
		void OnLegsRButtonClicked() { pCharacter->LegsPrevious(); }
	UFUNCTION()
		void OnHandsLButtonClicked() { pCharacter->HandsNext(); }
	UFUNCTION()
		void OnHandsRButtonClicked() { pCharacter->HandsPrevious(); }
	UFUNCTION()
		void OnFaceButtonClicked();
	UFUNCTION()
		void OnGenderButtonClicked();
	UFUNCTION()
		void OnConfirmButtonClicked();

	ATFPShooterCharacter* pCharacter;
	UTFPShooterSaveGame* saveGameInstance;
	bool isMale = true;
};
