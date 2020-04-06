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

protected:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	bool GetSightrayHitLocation(OUT FVector& HitLocation) const;
	void AimTowardsCrosshair();

public:
	virtual void Tick(float DeltaSeconds) override;

	
};
