// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "BattleTank.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward Declarations
class UTankBarrel; 
class UTankTurret_SMC;
class UTankAimingComponent;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret_SMC* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	void AimAt(FVector HitLocation);


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 5000; 

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//local ref for spawing projectile
	UTankBarrel* Barrel = nullptr; 

	double LastFireTime = 0;
	float ReloadTimeInSeconds = 3;
};
