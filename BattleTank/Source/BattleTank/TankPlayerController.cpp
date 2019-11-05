// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Not Possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possessing a %s"),*(ControlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void  ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;//Out Parameter;

	if (GetSightRayHitLoction(HitLocation))//has a "side-effect", is going to ine trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}
	
//get world location if Linetrace through crossbar,true if it ht landscape
bool ATankPlayerController::GetSightRayHitLoction(FVector& HitLocation)
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairLocationX, ViewportSizeY * CrossHairLocationY);
	
	FVector LookDirection;
	//"De-Project" the screen position of crosshair to world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line trace along the look direction, and see what we hit(up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
		{
		HitLocation = HitResult.Location;
		return true;
		}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const//it is in unit vector
{
	FVector CameraWorldLocation;//to be discarded
	DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation, LookDirection);
	return true;
}