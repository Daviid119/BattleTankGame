// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector&) const;

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair inersects the word
	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D, FVector& ) const;

	bool GetVectorHitLocation(FVector, FVector&) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333;	
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

};
