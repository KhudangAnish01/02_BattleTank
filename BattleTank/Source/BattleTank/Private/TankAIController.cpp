// Fill out your copyright notice in the Description page of Project Settings.


#include "C:/Users/Hp/OneDrive/Documents/02_BattleTank/BattleTank/Source/BattleTank/Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Not Possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Possessing a %s"), *(ControlledTank->GetName()));
	}
}
	

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
