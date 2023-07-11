#include "AvatarSelectionLevel.h"

void AAvatarSelectionLevel::BeginPlay()
{
	Super::BeginPlay();

	playerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());

	if (playerController)
	{
		playerController->SetViewTargetWithBlend(bodyCamera);
		playerController->bShowMouseCursor = true;
	}

	bodyPickUserWidget = CreateWidget<UUserWidget>(GetWorld(), bodyPickWidget);
	bodyPickWidgetInstance = Cast<UBodyPickWidget>(bodyPickUserWidget);
	bodyPickUserWidget->AddToViewport();
	facePickUserWidget = CreateWidget<UUserWidget>(GetWorld(), facePickWidget);
	facePickWidgetInstance = Cast<UFacePickWidget>(facePickUserWidget);

	bodyPickWidgetInstance->delegateSwitchCamera.AddDynamic(this, &AAvatarSelectionLevel::SwitchCamera);
	facePickWidgetInstance->delegateSwitchCamera.AddDynamic(this, &AAvatarSelectionLevel::SwitchCamera);
}

void AAvatarSelectionLevel::SwitchCamera()
{
	if (isFaceCamOpen)
	{
		playerController->SetViewTargetWithBlend(bodyCamera, cameraBlendingTime);
		isFaceCamOpen = false;
		bodyPickUserWidget->AddToViewport();
		facePickUserWidget->RemoveFromParent();
	}
	else
	{
		playerController->SetViewTargetWithBlend(faceCamera, cameraBlendingTime);
		isFaceCamOpen = true;
		bodyPickUserWidget->RemoveFromParent();
		facePickUserWidget->AddToViewport();
	}
}

