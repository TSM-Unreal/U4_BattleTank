// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankPlayerController.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ATankAIController BeginPlay"));
	ATank* AITank = GetControlledTank();
	if (AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController - AI Possessed Tank: %s"), *AITank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController - Not possessing AI Tank"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController - Player Tank: %s"), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController - Player Tank Not Found"));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank()) 
	{
		//TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready

	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	ATankPlayerController* TankPlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!TankPlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController - Not found!"));
		return nullptr;
	}
	
	return Cast<ATank>(TankPlayerController->GetPawn());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

