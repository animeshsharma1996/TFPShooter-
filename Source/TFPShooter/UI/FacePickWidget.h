#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../PlayerCharacter/TFPShooterCharacter.h"
#include "FacePickWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateSwitchFaceCam);

UCLASS()
class TFPSHOOTER_API UFacePickWidget : public UUserWidget
{
	GENERATED_BODY()
		virtual bool Initialize() override;

public :
	UPROPERTY()
		FDelegateSwitchFaceCam delegateSwitchCamera;

protected :
	UPROPERTY(meta = (BindWidget))
		class UButton* hairPreviousButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* hairNextButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* eyebrowPreviousButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* eyebrowNextButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* bodyButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* beardPreviousButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* beardNextButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* facePreviousButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* faceNextButton;

private :
	UFUNCTION()
		void OnBodyButtonClicked();
	UFUNCTION()
		void OnHairPreviousButtonClicked() { pCharacter->HairPrevious(); }
	UFUNCTION()
		void OnHairNextButtonClicked() { pCharacter->HairNext(); }
	UFUNCTION()
		void OnEyebrowPreviousButtonClicked() { pCharacter->EyebrowPrevious(); }
	UFUNCTION()
		void OnEyebrowNextButtonClicked() { pCharacter->EyebrowNext(); }
	UFUNCTION()
		void OnBeardPreviousButtonClicked() { pCharacter->BeardPrevious(); }
	UFUNCTION()
		void OnBeardNextButtonClicked() { pCharacter->BeardNext(); }
	UFUNCTION()
		void OnFacePreviousButtonClicked() { pCharacter->FacePrevious(); }
	UFUNCTION()
		void OnFaceNextButtonClicked() { pCharacter->FaceNext(); }

	ATFPShooterCharacter* pCharacter;
};
