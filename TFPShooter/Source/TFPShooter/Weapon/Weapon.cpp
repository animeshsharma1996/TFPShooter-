#include "Weapon.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::Fire()
{

}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

