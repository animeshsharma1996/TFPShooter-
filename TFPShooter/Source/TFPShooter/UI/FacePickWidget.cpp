#include "FacePickWidget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>

bool UFacePickWidget::Initialize()
{
	Super::Initialize();

	pCharacter = Cast<ATFPShooterCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATFPShooterCharacter::StaticClass()));

	hairPreviousButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnHairPreviousButtonClicked);
	hairNextButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnHairNextButtonClicked);
	eyebrowNextButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnEyebrowNextButtonClicked);
	eyebrowPreviousButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnEyebrowPreviousButtonClicked);
	bodyButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnBodyButtonClicked);
	beardPreviousButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnBeardPreviousButtonClicked);
	beardNextButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnBeardNextButtonClicked);
	facePreviousButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnFacePreviousButtonClicked);
	faceNextButton->OnClicked.AddDynamic(this, &UFacePickWidget::OnFaceNextButtonClicked);

	return false;
}

void UFacePickWidget::OnBodyButtonClicked()
{

}
