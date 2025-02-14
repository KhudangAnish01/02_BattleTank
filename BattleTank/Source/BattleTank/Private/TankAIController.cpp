// Fill out your copyright notice in the Description page of Project Settings.

#include"Engine/World.h"
#include "C:/Users/Hp/OneDrive/Documents/02_BattleTank/BattleTank/Source/BattleTank/Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player  %s"), *(PlayerTank->GetName()));
	}
}
	
// Called every frame
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetPlayerTank())
	{
		//TODO Move Towards Player
		//Aim Towards Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire If Ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

