
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TFPShooterAnimation.generated.h"

UCLASS()
class TFPSHOOTER_API UTFPShooterAnimation : public UAnimInstance
{
	GENERATED_BODY()
		virtual void NativeInitializeAnimation() override;
		virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly)
		FVector2D movementVector;
	UPROPERTY(BlueprintReadOnly)
		bool shouldMove;
	UPROPERTY(BlueprintReadOnly)
		bool isFalling;

private :
		ACharacter* character = nullptr;
		UCharacterMovementComponent* movementComponent;
		FVector velocity;
		float groundSpeed;
};
