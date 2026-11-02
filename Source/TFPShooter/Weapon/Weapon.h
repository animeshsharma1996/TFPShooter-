#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class TFPSHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

protected:
	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
		UMaterial* weaponMaterial;
	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
		float weaponDamage = 10.0f;
	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
		float weaponRange = 10000.0f;

	virtual void Initialiase() {}

public:	
	UFUNCTION()
		virtual void Fire() {}
};
