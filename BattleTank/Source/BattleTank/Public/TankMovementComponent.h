// Copyright Priest_kod

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankTrack.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 *  Resposible for driving tank tracks
 */

UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnLeft(float Throw);


	
private:

	//Called form the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack*  LeftTrack = nullptr;
	UTankTrack*  RightTrack = nullptr;

};
