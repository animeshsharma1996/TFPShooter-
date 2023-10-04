#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Gun.generated.h"

UCLASS()
class TFPSHOOTER_API AGun : public AWeapon
{
	GENERATED_BODY()

protected :	
	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
		float gunFireRate = 100.0f;
	UFUNCTION()	
		virtual void Initialiase() override;

public:
	virtual void Fire() override;
};
