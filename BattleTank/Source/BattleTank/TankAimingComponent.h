// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward Declaration
class UTankBarrel; 
class UTankTurret_SMC;

//Holds Paramters for Barrel Properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret_SMC* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	//TODO Set Turret Reference

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret_SMC* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FVector AimDirection);
	
};
