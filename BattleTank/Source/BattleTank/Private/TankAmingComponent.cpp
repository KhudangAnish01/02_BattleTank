// Fill out your copyright notice in the Description page of Project Settings.


#include "C:/Users/Hp/OneDrive/Documents/02_BattleTank/BattleTank/Source/BattleTank/Public/TankAmingComponent.h"
#include "BattleTankGameModeBase.h"

// Sets default values for this component's properties
UTankAmingComponent::UTankAmingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAmingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}



// Called when the game starts
void UTankAmingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTankAmingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAmingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Firing at %f"), LaunchSpeed);
}