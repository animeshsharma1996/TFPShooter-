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
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->TargetArmLength = 300.0f; 
	cameraBoom->bUsePawnControlRotation = true; 

	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName); 
	followCamera->bUsePawnControlRotation = true; 
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

	beardMesh = FindComponentByClass<UStaticMeshComponent>();
	hairMesh = FindComponentByClass<UStaticMeshComponent>();
	eyesMesh = FindComponentByClass<UStaticMeshComponent>();
	eyebrowMesh = FindComponentByClass<UStaticMeshComponent>();
	mesh = FindComponentByClass<USkeletalMeshComponent>();
	chestMesh = FindComponentByClass<USkeletalMeshComponent>();
	handsMesh = FindComponentByClass<USkeletalMeshComponent>();
	legsMesh = FindComponentByClass<USkeletalMeshComponent>();

	AttachBodyParts(chestMesh);
	AttachBodyParts(handsMesh);
	AttachBodyParts(legsMesh);

	eyesMesh->AttachToComponent(mesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));
	eyebrowMesh->AttachToComponent(mesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));
	hairMesh->AttachToComponent(mesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));
	beardMesh->AttachToComponent(mesh, FAttachmentTransformRules::KeepRelativeTransform, FName("headSocket"));

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
		faceIndexMale = NextSkeletalMesh(faceIndexMale, faceArrayMale, mesh);
	}
	else
	{
		faceIndexFemale = NextSkeletalMesh(faceIndexFemale, faceArrayFemale, mesh);
	}
}

void ATFPShooterCharacter::FacePrevious()
{
	if (isMale)
	{
		faceIndexMale = PreviousSkeletalMesh(faceIndexMale, faceArrayMale, mesh);
	}
	else
	{
		faceIndexFemale = PreviousSkeletalMesh(faceIndexFemale, faceArrayFemale, mesh);
	}
}

void ATFPShooterCharacter::AttachBodyParts(USkeletalMeshComponent* bodyComponent)
{
	FVector location = mesh->GetComponentLocation();
	FRotator rotation = mesh->GetComponentRotation();
	bodyComponent->SetWorldLocationAndRotation(location, rotation, false);
	bodyComponent->SetLeaderPoseComponent(mesh);
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
		chestMesh->SetSkinnedAssetAndUpdate(chestArrayFemale[chestIndexFemale], true);
		mesh->SetSkinnedAssetAndUpdate(faceArrayFemale[faceIndexFemale], true);
		legsMesh->SetSkinnedAssetAndUpdate(legsArrayFemale[legsIndexFemale], true);
		handsMesh->SetSkinnedAssetAndUpdate(handsArrayFemale[handsIndexFemale], true);
		hairMesh->SetStaticMesh(hairArrayFemale[hairIndexFemale]);
		eyesMesh->SetStaticMesh(eyesArrayFemale[eyesIndexFemale]);
		beardMesh->SetStaticMesh(nullptr);
	}
	else
	{
		isMale = true;
		chestMesh->SetSkinnedAssetAndUpdate(chestArrayMale[chestIndexMale], true);
		mesh->SetSkinnedAssetAndUpdate(faceArrayMale[faceIndexMale], true);
		legsMesh->SetSkinnedAssetAndUpdate(legsArrayMale[legsIndexMale], true);
		handsMesh->SetSkinnedAssetAndUpdate(handsArrayMale[handsIndexMale], true);
		hairMesh->SetStaticMesh(hairArrayMale[hairIndexMale]);
		eyesMesh->SetStaticMesh(eyesArrayMale[eyesIndexMale]);
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
	mesh->SetSkinnedAssetAndUpdate(face, true);
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


