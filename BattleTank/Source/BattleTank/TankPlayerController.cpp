// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();


	//UE_LOG(LogTemp, Warning, TEXT("Player Contoller Begin Play"));


	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing a tank."));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing %s."), *(ControlledTank->GetName()));

	}
	

}



	

	// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller ticking."));

	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{

		//UE_LOG(LogTemp, Warning, TEXT("PlayerController Get Tank running."));
		return Cast<ATank>(GetPawn());
};



void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}
	
	FVector HitLocation; //OUT parameter
	if (GetSightRayHitLocation(HitLocation)) //Has Side effect, is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		//TODO tell controll tank aim at this point
	}
}


//get world location through crosshair line trace, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{

	//GetWorld()->GetFirstPlayerController()->LineOfSightTo(
	//	GetWorld()->Get, //Tank Controller is from Actor; use getpawn()?
	//	HitLocation,
	//	false
	//);

	//Get Playercontrolledtank and vecotr from crosshair
		//send trace to world
	//if hit something
	//return true
		//return hitvector
	//else return false
		//return no hitvetor?
	HitLocation = FVector(1.0);
	return true;
}