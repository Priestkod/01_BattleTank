// Copyright Priest_kod

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

//forward declarations
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BluePrintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BLueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
