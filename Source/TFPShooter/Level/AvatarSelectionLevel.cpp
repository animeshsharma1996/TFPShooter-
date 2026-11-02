#include "AvatarSelectionLevel.h"
#include <Kismet/GameplayStatics.h>

void AAvatarSelectionLevel::BeginPlay()
{
	Super::BeginPlay();

	playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pCharacter = Cast<ATFPShooterCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATFPShooterCharacter::StaticClass()));

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

void AAvatarSelectionLevel::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (playerController->IsInputKeyDown(EKeys::LeftMouseButton))
	{ 
		float mouseX = 0;
		float mouseY = 0;
		playerController->GetInputMouseDelta(mouseX, mouseY);
		FRotator rotator = FRotator(0, -mouseX*5.0f, 0);
		pCharacter->AddActorWorldRotation(rotator);
	}
}