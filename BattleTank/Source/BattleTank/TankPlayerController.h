// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

// Responsible for helping the player to aim
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 1.f/3.f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRangeCM = 10000.f * 100.f;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

	virtual void BeginPlay() override;
	bool GetSightrayHitLocation(OUT FVector& HitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, OUT FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, OUT FVector& LookDirection) const;
	void AimTowardsCrosshair();

	virtual void Tick(float DeltaSeconds) override;

	
};
