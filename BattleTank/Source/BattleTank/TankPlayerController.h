// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Engine/World.h"
#include"C:/Users/Hp/OneDrive/Documents/02_BattleTank/BattleTank/Source/BattleTank/Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	//start the tank's barrel so that shot will hit where its
	//crosshair intersect with world
	void AimTowardsCrossHair();

	//return an out parameter,true if it hit landscpae
	bool GetSightRayHitLoction(FVector& OutHitLocation);

	UPROPERTY(EditAnyWhere)
		float CrossHairLocationX = 0.5;

	UPROPERTY(EditAnyWhere)
		float CrossHairLocationY = 0.333;


	UPROPERTY(EditAnyWhere)
		float LineTraceRange= 100000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
