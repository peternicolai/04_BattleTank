// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT("Player Contoller Begin Play"));


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

ATank* ATankPlayerController::GetControlledTank() const
{

		UE_LOG(LogTemp, Warning, TEXT("PlayerController Get Tank running."));
		return Cast<ATank>(GetPawn());
};

