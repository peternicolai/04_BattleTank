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
		GetControlledTank()->AimAt(HitLocation);
	}
}


//get world location through crosshair line trace, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{

	//find crosshair
	int32 ViewPortSizeX, ViewPortSizeY;
	
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto ScreenLocation = FVector2D	(ViewPortSizeX*CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);

	//"deproject" screen position of CH to world position
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line trace along that look direction and see what we hit within max range
		GetLookVectorHitLocation(LookDirection, HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location is: %s."), *HitLocation.ToString())
	}
	

	//HitLocation = FVector(1.0);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{ 
	FVector CameraWorldLocation; //ignored but must be passed in
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		)
		)//line trace succeeds
	{
		HitLocation = HitResult.Location;
		//set hit loc
		return true;
	}
	HitLocation = FVector(0);
	return false; //Line trace didn't succeed
}