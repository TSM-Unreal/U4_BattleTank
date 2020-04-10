// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%s: Throttle Set at %f"), *GetName(), Throttle);

	// TODO Clamp throttle values

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

