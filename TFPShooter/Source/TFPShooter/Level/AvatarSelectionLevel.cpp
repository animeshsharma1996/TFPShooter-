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
}

void AAvatarSelectionLevel::SwitchCamera()
{
	if (isFaceCamOpen)
	{
		playerController->SetViewTargetWithBlend(bodyCamera, cameraBlendingTime);
		isFaceCamOpen = false;
		bodyPickUserWidget->AddToViewport();
		facePickUserWidget->RemoveFromViewport();
	}
	else
	{
		playerController->SetViewTargetWithBlend(faceCamera, cameraBlendingTime);
		isFaceCamOpen = true;
		bodyPickUserWidget->RemoveFromViewport();
		facePickUserWidget->AddToViewport();
	}
}

