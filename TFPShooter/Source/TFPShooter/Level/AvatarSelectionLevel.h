#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "../UI/BodyPickWidget.h"
#include "../UI/FacePickWidget.h"
#include "../PlayerCharacter/TFPShooterCharacter.h"
#include "AvatarSelectionLevel.generated.h"

UCLASS()
class TFPSHOOTER_API AAvatarSelectionLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public :
	UFUNCTION()
		void SwitchCamera();

protected :
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<UBodyPickWidget> bodyPickWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<UFacePickWidget> facePickWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AActor* bodyCamera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AActor* faceCamera;

private :
		UUserWidget* bodyPickUserWidget;
		UUserWidget* facePickUserWidget;
		UBodyPickWidget* bodyPickWidgetInstance;
		UFacePickWidget* facePickWidgetInstance;
		APlayerController* playerController;
		ATFPShooterCharacter* pCharacter;
		float cameraBlendingTime = 0.5f;
		bool isFaceCamOpen = false;
};
