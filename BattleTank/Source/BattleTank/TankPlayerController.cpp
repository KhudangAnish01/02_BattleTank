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
	UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
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
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		//TODO Tell controlled tank to aim at this point
	}
	}
	
//get world location if Linetrace through crossbar,true if it ht landscape
bool ATankPlayerController::GetSightRayHitLoction(FVector& OutHitLocation)
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX,ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairLocationX, ViewportSizeY * CrossHairLocationY);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	//"De-Project" the screen position of crosshair to world direction
	//Line trace along the look direction, and see what we hit(up to max range)
	return true;
}