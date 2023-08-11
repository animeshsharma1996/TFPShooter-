#include "TFPShooterAnimation.h"
#include "TFPShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UTFPShooterAnimation::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	character = Cast<ACharacter>(GetOwningActor());

	if (character)
	{
		movementComponent = character->GetCharacterMovement();
	}
}

void UTFPShooterAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (character)
	{
		velocity = movementComponent->Velocity;
		FVector2D velocityXY = FVector2D(velocity.X, velocity.Y);
		groundSpeed = velocityXY.Length();
		float movementVectorX = FVector::DotProduct(character->GetActorRightVector(), velocity);
		float movementVectorY = FVector::DotProduct(character->GetActorForwardVector(), velocity);
		movementVector = FVector2D(movementVectorX, movementVectorY);
		shouldMove = (movementComponent->GetCurrentAcceleration() != FVector(0.0f,0.0f,0.0f)) && (groundSpeed > 3.0f);
		isFalling = movementComponent->IsFalling();
	}
}
