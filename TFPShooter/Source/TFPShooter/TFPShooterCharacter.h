#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TFPShooterCharacter.generated.h"

UCLASS(config=Game)
class ATFPShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATFPShooterCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
		float baseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
		float baseLookUpRate;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return cameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return followCamera; }

	UFUNCTION()
		void ChestNext();
	UFUNCTION()
		void ChestPrevious();
	UFUNCTION()
		void LegsNext();
	UFUNCTION()
		void LegsPrevious();
	UFUNCTION()
		void HandsNext();
	UFUNCTION()
		void HandsPrevious();
	UFUNCTION()
		void BeardNext();
	UFUNCTION()
		void BeardPrevious();
	UFUNCTION()
		void HairNext();
	UFUNCTION()
		void HairPrevious();
	UFUNCTION()
		void EyebrowNext();
	UFUNCTION()
		void EyebrowPrevious();
	UFUNCTION()
		void FaceNext();
	UFUNCTION()
		void FacePrevious();

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
		void SwitchGender();
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
	UFUNCTION()
		void GetAvatar();

		void MoveForward(float Value);
		void MoveRight(float Value);
		void TurnAtRate(float Rate);
		void LookUpAtRate(float Rate);
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		virtual void BeginPlay() override;

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
		TArray<class UStaticMesh*> eyesArrayMale;
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
		TArray<class UStaticMesh*> eyesArrayFemale;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Body Parts")
		TArray<class UStaticMesh*> eyebrowArrayFemale;

		int faceIndexMale = 0;
		int chestIndexMale = 0;
		int handsIndexMale = 0;
		int legsIndexMale = 0;
		int beardIndexMale = 0;
		int hairIndexMale = 0;
		int eyesIndexMale = 0;
		int eyebrowIndexMale = 0;

		int faceIndexFemale = 0;
		int chestIndexFemale = 0;
		int handsIndexFemale = 0;
		int legsIndexFemale = 0;
		int hairIndexFemale = 0;
		int eyesIndexFemale = 0;
		int eyebrowIndexFemale = 0;

		bool isMale = true;
		class UStaticMeshComponent* beardMesh;
		class UStaticMeshComponent* hairMesh;
		class UStaticMeshComponent* eyesMesh;
		class UStaticMeshComponent* eyebrowMesh;
		class USkeletalMeshComponent* mesh;
		class USkeletalMeshComponent* chestMesh;
		class USkeletalMeshComponent* handsMesh;
		class USkeletalMeshComponent* legsMesh;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* cameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* followCamera;
};

