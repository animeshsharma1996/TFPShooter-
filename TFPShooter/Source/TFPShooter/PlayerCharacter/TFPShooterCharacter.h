#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Chaos/Pair.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "TFPShooterCharacter.generated.h"

USTRUCT() struct FMeshPair
{
	GENERATED_BODY()

	TArray<USkeletalMesh*> skeletalMeshes;
	TArray<UStaticMesh*> staticMeshes;
};

UCLASS(config=Game)
class ATFPShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATFPShooterCharacter();
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Camera)
		float baseTurnAtRate;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Camera)
		float baseLookUpAtRate;	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Camera)
		float baseTurnRate;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Camera)
		float baseLookUpRate;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return cameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return followCamera; }

	UFUNCTION(BlueprintCallable)
		void ChestNext();
	UFUNCTION(BlueprintCallable)
		void ChestPrevious();
	UFUNCTION(BlueprintCallable)
		void LegsNext();
	UFUNCTION(BlueprintCallable)
		void LegsPrevious();
	UFUNCTION(BlueprintCallable)
		void HandsNext();
	UFUNCTION(BlueprintCallable)
		void HandsPrevious();
	UFUNCTION(BlueprintCallable)
		void BeardNext();
	UFUNCTION(BlueprintCallable)
		void BeardPrevious();
	UFUNCTION(BlueprintCallable)
		void HairNext();
	UFUNCTION(BlueprintCallable)
		void HairPrevious();
	UFUNCTION(BlueprintCallable)
		void EyebrowNext();
	UFUNCTION(BlueprintCallable)
		void EyebrowPrevious();
	UFUNCTION(BlueprintCallable)
		void FaceNext();
	UFUNCTION(BlueprintCallable)
		void FacePrevious();
	UFUNCTION(BlueprintCallable)
		void SwitchGender();
	UFUNCTION()
		FMeshPair GetAvatar();

protected:
	UFUNCTION()
		void AttachBodyParts(USkeletalMeshComponent* bodyComponent);
	UFUNCTION()
		int NextSkeletalMesh
		(	
			int arrayIndex, TArray<USkeletalMesh*> skeletalMeshArray, USkeletalMeshComponent* skeletalMeshComponent
		);
	UFUNCTION()
		int PreviousSkeletalMesh
		(
			int arrayIndex, TArray<USkeletalMesh*> skeletalMeshArray, USkeletalMeshComponent* skeletalMeshComponent
		);
	UFUNCTION()
		int NextStaticMesh
		(
			int arrayIndex, TArray<UStaticMesh*> staticMeshArray, UStaticMeshComponent* staticMeshComponent
		);
	UFUNCTION()
		int PreviousStaticMesh
		(
			int arrayIndex, TArray<UStaticMesh*> staticMeshArray, UStaticMeshComponent* staticMeshComponent
		);
	UFUNCTION()
		void SetAvatar
		(
			USkeletalMesh* face,
			USkeletalMesh* legs,
			USkeletalMesh* hands,
			USkeletalMesh* chest,
			UStaticMesh* eyebrow,
			UStaticMesh* hair,
			UStaticMesh* beard
		);

		void MoveForward(const FInputActionInstance& actionInstance);
		void MoveRight(const FInputActionInstance& actionInstance);
		void Turn(const FInputActionInstance& actionInstance) { AddControllerYawInput(baseTurnRate * actionInstance.GetValue().Get<float>()); }
		void TurnAtRate(const FInputActionInstance& actionInstance);
		void LookUp(const FInputActionInstance& actionInstance) { AddControllerPitchInput(baseLookUpRate * actionInstance.GetValue().Get<float>()); }
		void LookUpAtRate(const FInputActionInstance& actionInstance);
		void SwitchPerspective(const FInputActionInstance& actionInstance);
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputMappingContext* mappingContext = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* jumpIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* moveForwardIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* moveRightIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* turnIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* turnRateIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* lookUpIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* lookUpRateIA = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
		class UInputAction* switchPerspectiveIA = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> faceArrayMale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> chestArrayMale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> handsArrayMale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> legsArrayMale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class UStaticMesh*> beardArrayMale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class UStaticMesh*> hairArrayMale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class UStaticMesh*> eyebrowArrayMale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> faceArrayFemale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> chestArrayFemale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> handsArrayFemale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class USkeletalMesh*> legsArrayFemale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class UStaticMesh*> hairArrayFemale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class UStaticMesh*> eyebrowArrayFemale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
        class AGun* gunClass = nullptr;

		int faceIndexMale = 0;
		int chestIndexMale = 0;
		int handsIndexMale = 0;
		int legsIndexMale = 0;
		int beardIndexMale = 0;
		int hairIndexMale = 0;
		int eyebrowIndexMale = 0;

		int faceIndexFemale = 0;
		int chestIndexFemale = 0;
		int handsIndexFemale = 0;
		int legsIndexFemale = 0;
		int hairIndexFemale = 0;
		int eyebrowIndexFemale = 0;

		bool isMale = true;

		class USkeletalMeshComponent* mainMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class USkeletalMeshComponent* chestMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class USkeletalMeshComponent* handsMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class USkeletalMeshComponent* legsMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* beardMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* hairMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* eyesMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* eyebrowMesh = nullptr;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* cameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* followCamera;	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* fPCamera;

		APlayerController* playerController = nullptr;
		bool isFirstPerson = false;
};	

