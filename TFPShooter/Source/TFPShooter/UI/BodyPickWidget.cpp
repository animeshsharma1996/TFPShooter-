#include "BodyPickWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include <Kismet/GameplayStatics.h>
#include <Blueprint/WidgetBlueprintLibrary.h>

bool UBodyPickWidget::Initialize()
{
	Super::Initialize();

	pCharacter = Cast<ATFPShooterCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATFPShooterCharacter::StaticClass()));

	chestLButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnChestLButtonClicked);
	chestRButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnChestRButtonClicked);
	legsLButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnLegsLButtonClicked);
	legsRButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnLegsRButtonClicked);
	handsLButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnHandsLButtonClicked);
    handsRButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnHandsRButtonClicked);
	faceButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnFaceButtonClicked);
	genderButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnGenderButtonClicked);
	confirmButton->OnClicked.AddDynamic(this, &UBodyPickWidget::OnConfirmButtonClicked);

	return false;
}

void UBodyPickWidget::OnFaceButtonClicked()
{

}

void UBodyPickWidget::OnGenderButtonClicked()
{
	if (isMale)
	{
		genderButtonText->SetText(FText::FromString("Female"));
		isMale = false;
	}
	else
	{
		genderButtonText->SetText(FText::FromString("Male"));
		isMale = true;
	}
	pCharacter->SwitchGender();
}

void UBodyPickWidget::OnConfirmButtonClicked()
{
	FMeshPair meshPair = pCharacter->GetAvatar();
	saveGameInstance = Cast<UTFPShooterSaveGame>(UGameplayStatics::CreateSaveGameObject(tfpShooterSaveGame));
	saveGameInstance->SaveCharacterMeshes(meshPair.skeletalMeshes, meshPair.staticMeshes);
	UGameplayStatics::SaveGameToSlot(saveGameInstance, "SavedCharacterMesh", 0);
	UGameplayStatics::OpenLevel(GetWorld(), "Stylized_Egypt_Demo");
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(UGameplayStatics::GetPlayerController(GetWorld(), 0), false);
}
