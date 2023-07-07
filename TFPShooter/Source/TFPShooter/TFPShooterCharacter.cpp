#include "TFPShooterCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "SaveGame/TFPShooterSaveGame.h"
#include <Kismet/GameplayStatics.h>

ATFPShooterCharacter::ATFPShooterCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	baseTurnRate = 45.f;
	baseLookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; 	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
	GetCharacterMovement()->JumpZVelocity = 300.f;
	GetCharacterMovement()->AirControl = 0.2f;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->TargetArmLength = 300.0f; 
	cameraBoom->bUsePawnControlRotation = true; 

	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName); 
	followCamera->bUsePawnControlRotation = true; 

	mainMesh = GetMesh();
	chestMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ChestMesh"));
	chestMesh->SetupAttachment(mainMesh, NAME_None);

	handsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandsMesh"));
	handsMesh->SetupAttachment(mainMesh, NAME_None);

	legsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LegsMesh"));
	legsMesh->SetupAttachment(mainMesh, NAME_None);

	eyesMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EyesMesh"));
	eyesMesh->SetupAttachment(mainMesh, FName("headSocket"));

	eyebrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EyebrowMesh"));
	eyebrowMesh->SetupAttachment(mainMesh, FName("headSocket"));

	hairMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HairMesh"));
	hairMesh->SetupAttachment(mainMesh, FName("headSocket"));

	beardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BeardMesh"));
	beardMesh->SetupAttachment(mainMesh, FName("headSocket"));
}

void ATFPShooterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATFPShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATFPShooterCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATFPShooterCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATFPShooterCharacter::LookUpAtRate);
}

void ATFPShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	AttachBodyParts(chestMesh);
	AttachBodyParts(handsMesh);
	AttachBodyParts(legsMesh);

	//eyesMesh->AttachToComponent(mainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));
	//eyebrowMesh->AttachToComponent(mainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));
	//hairMesh->AttachToComponent(mainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));
	//beardMesh->AttachToComponent(mainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));

	if (UGameplayStatics::DoesSaveGameExist("SavedCharacterMesh", 0))
	{
		UTFPShooterSaveGame* saveGame = Cast<UTFPShooterSaveGame>(UGameplayStatics::LoadGameFromSlot("SavedCharacterMesh", 0));
		if (!saveGame->LoadSkeletalMeshes().IsEmpty() && !saveGame->LoadStaticMeshes().IsEmpty())
		{
			SetAvatar
			(
				saveGame->LoadSkeletalMeshes()[0],
				saveGame->LoadSkeletalMeshes()[1],
				saveGame->LoadSkeletalMeshes()[2],
				saveGame->LoadSkeletalMeshes()[3],
				saveGame->LoadStaticMeshes()[0],
				saveGame->LoadStaticMeshes()[1],
				saveGame->LoadStaticMeshes()[2]
			);
		}
	}
}

void ATFPShooterCharacter::AttachBodyParts(USkeletalMeshComponent* bodyComponent)
{
	FVector location = mainMesh->GetComponentLocation();
	FRotator rotation = mainMesh->GetComponentRotation();
	bodyComponent->SetWorldLocationAndRotation(location, rotation, false);
	bodyComponent->SetLeaderPoseComponent(mainMesh);
}


void ATFPShooterCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * baseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATFPShooterCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * baseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATFPShooterCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATFPShooterCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ATFPShooterCharacter::ChestNext()
{
	if (isMale)
	{
		chestIndexMale = NextSkeletalMesh(chestIndexMale, chestArrayMale, chestMesh);
	}
	else
	{
		chestIndexFemale = NextSkeletalMesh(chestIndexFemale, chestArrayFemale, chestMesh);
	}
}

void ATFPShooterCharacter::ChestPrevious()
{
	if (isMale)
	{
		chestIndexMale = PreviousSkeletalMesh(chestIndexMale, chestArrayMale, chestMesh);
	}
	else
	{
		chestIndexFemale = PreviousSkeletalMesh(chestIndexFemale, chestArrayFemale, chestMesh);
	}
}

void ATFPShooterCharacter::LegsNext()
{
	if (isMale)
	{
		legsIndexMale = NextSkeletalMesh(legsIndexMale, legsArrayMale, legsMesh);
	}
	else
	{
		legsIndexFemale = NextSkeletalMesh(legsIndexFemale, legsArrayFemale, legsMesh);
	}
}

void ATFPShooterCharacter::LegsPrevious()
{
	if (isMale)
	{
		legsIndexMale = PreviousSkeletalMesh(legsIndexMale, legsArrayMale, legsMesh);
	}
	else
	{
		legsIndexFemale = PreviousSkeletalMesh(legsIndexFemale, legsArrayFemale, legsMesh);
	}
}

void ATFPShooterCharacter::HandsNext()
{
	if (isMale)
	{
		handsIndexMale = NextSkeletalMesh(handsIndexMale, handsArrayMale, handsMesh);
	}
	else
	{
		handsIndexFemale = NextSkeletalMesh(handsIndexFemale, handsArrayFemale, handsMesh);
	}
}

void ATFPShooterCharacter::HandsPrevious()
{
	if (isMale)
	{
		handsIndexMale = PreviousSkeletalMesh(handsIndexMale, handsArrayMale, handsMesh);
	}
	else
	{
		handsIndexFemale = PreviousSkeletalMesh(handsIndexFemale, handsArrayFemale, handsMesh);
	}
}

void ATFPShooterCharacter::BeardNext()
{
	if (isMale)
	{
		beardIndexMale = NextStaticMesh(beardIndexMale, beardArrayMale, beardMesh);
	}
}

void ATFPShooterCharacter::BeardPrevious()
{
	if (isMale)
	{
		beardIndexMale = PreviousStaticMesh(beardIndexMale, beardArrayMale, beardMesh);
	}
}

void ATFPShooterCharacter::HairNext()
{
	if (isMale)
	{
		hairIndexMale = NextStaticMesh(hairIndexMale, hairArrayMale, hairMesh);
	}
	else
	{
		hairIndexFemale = NextStaticMesh(hairIndexFemale, hairArrayFemale, hairMesh);
	}
}

void ATFPShooterCharacter::HairPrevious()
{
	if (isMale)
	{
		hairIndexMale = PreviousStaticMesh(hairIndexMale, hairArrayMale, hairMesh);
	}
	else
	{
		hairIndexFemale = PreviousStaticMesh(hairIndexFemale, hairArrayFemale, hairMesh);
	}
}

void ATFPShooterCharacter::EyebrowNext()
{
	if (isMale)
	{
		eyebrowIndexMale = NextStaticMesh(eyebrowIndexMale, eyebrowArrayMale, eyebrowMesh);
	}
	else
	{
		eyebrowIndexFemale = NextStaticMesh(eyebrowIndexFemale, eyebrowArrayFemale, eyebrowMesh);
	}
}

void ATFPShooterCharacter::EyebrowPrevious()
{
	if (isMale)
	{
		eyebrowIndexMale = PreviousStaticMesh(eyebrowIndexMale, eyebrowArrayMale, eyebrowMesh);
	}
	else
	{
		eyebrowIndexFemale = PreviousStaticMesh(eyebrowIndexFemale, eyebrowArrayFemale, eyebrowMesh);
	}
}

void ATFPShooterCharacter::FaceNext()
{
	if (isMale)
	{
		faceIndexMale = NextSkeletalMesh(faceIndexMale, faceArrayMale, mainMesh);
	}
	else
	{
		faceIndexFemale = NextSkeletalMesh(faceIndexFemale, faceArrayFemale, mainMesh);
	}
}

void ATFPShooterCharacter::FacePrevious()
{
	if (isMale)
	{
		faceIndexMale = PreviousSkeletalMesh(faceIndexMale, faceArrayMale, mainMesh);
	}
	else
	{
		faceIndexFemale = PreviousSkeletalMesh(faceIndexFemale, faceArrayFemale, mainMesh);
	}
}

int ATFPShooterCharacter::NextSkeletalMesh
(
	int arrayIndex, TArray<USkeletalMesh*> skeletalMeshArray, USkeletalMeshComponent* skeletalMeshComponent
)
{
	int localIndex = arrayIndex;
	++localIndex;
	if (localIndex >= skeletalMeshArray.Num())
	{
		localIndex = 0;
	}
	skeletalMeshComponent->SetSkinnedAssetAndUpdate(skeletalMeshArray[localIndex], true);

	return localIndex;
}

int ATFPShooterCharacter::PreviousSkeletalMesh
(
	int arrayIndex, TArray<USkeletalMesh*> skeletalMeshArray, USkeletalMeshComponent* skeletalMeshComponent
)
{
	int localIndex = arrayIndex;
	--localIndex;
	if (localIndex < 0)
	{
		localIndex = skeletalMeshArray.Num() - 1;
	}
	skeletalMeshComponent->SetSkinnedAssetAndUpdate(skeletalMeshArray[localIndex], true);

	return localIndex;
}

int ATFPShooterCharacter::NextStaticMesh
(
	int arrayIndex, TArray<UStaticMesh*> staticMeshArray, UStaticMeshComponent* staticMeshComponent
)
{
	int localIndex = arrayIndex;
	++localIndex;
	if (localIndex >= staticMeshArray.Num())
	{
		localIndex = 0;
	}
	staticMeshComponent->SetStaticMesh(staticMeshArray[localIndex]);

	return localIndex;
}

int ATFPShooterCharacter::PreviousStaticMesh
(
	int arrayIndex, TArray<UStaticMesh*> skeletalMeshArray, UStaticMeshComponent* skeletalMeshComponent
)
{
	int localIndex = arrayIndex;
	--localIndex;
	if (localIndex < 0)
	{
		localIndex = skeletalMeshArray.Num() - 1;
	}
	skeletalMeshComponent->SetStaticMesh(skeletalMeshArray[localIndex]);

	return localIndex;
}

void ATFPShooterCharacter::SwitchGender()
{
	if (isMale)
	{
		isMale = false;
		mainMesh->SetSkinnedAssetAndUpdate(faceArrayFemale[faceIndexFemale], true);
		chestMesh->SetSkinnedAssetAndUpdate(chestArrayFemale[chestIndexFemale], true);
		legsMesh->SetSkinnedAssetAndUpdate(legsArrayFemale[legsIndexFemale], true);
		handsMesh->SetSkinnedAssetAndUpdate(handsArrayFemale[handsIndexFemale], true);
		hairMesh->SetStaticMesh(hairArrayFemale[hairIndexFemale]);
		beardMesh->SetStaticMesh(nullptr);
	}
	else
	{
		isMale = true;
		mainMesh->SetSkinnedAssetAndUpdate(faceArrayMale[faceIndexMale], true);
		chestMesh->SetSkinnedAssetAndUpdate(chestArrayMale[chestIndexMale], true);
		legsMesh->SetSkinnedAssetAndUpdate(legsArrayMale[legsIndexMale], true);
		handsMesh->SetSkinnedAssetAndUpdate(handsArrayMale[handsIndexMale], true);
		hairMesh->SetStaticMesh(hairArrayMale[hairIndexMale]);
		beardMesh->SetStaticMesh(beardArrayMale[beardIndexMale]);
	}
}

void ATFPShooterCharacter::SetAvatar
(
	USkeletalMesh* face,
	USkeletalMesh* legs,
	USkeletalMesh* hands,
	USkeletalMesh* chest,
	UStaticMesh* eyebrow,
	UStaticMesh* hair,
	UStaticMesh* beard
)
{
	mainMesh->SetSkinnedAssetAndUpdate(face, true);
	legsMesh->SetSkinnedAssetAndUpdate(legs, true);
	handsMesh->SetSkinnedAssetAndUpdate(hands, true);
	chestMesh->SetSkinnedAssetAndUpdate(chest, true);
	eyebrowMesh->SetStaticMesh(eyebrow);
	hairMesh->SetStaticMesh(hair);
	beardMesh->SetStaticMesh(beard);
}

void ATFPShooterCharacter::GetAvatar()
{
	
}


