// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 1.f/3.f;
	UPROPERTY(EditAnywhere)
	float LineTraceRangeCM = 10000.f * 100.f;

protected:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	bool GetSightrayHitLocation(OUT FVector& HitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, OUT FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, OUT FVector& LookDirection) const;
	void AimTowardsCrosshair();

	virtual void Tick(float DeltaSeconds) override;

	
};
