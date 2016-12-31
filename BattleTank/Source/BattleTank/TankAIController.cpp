// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	//UE_LOG(LogTemp, Warning, TEXT("AI Contoller Begin Play"));


	auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a tank."));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing %s."), *(AIControlledTank->GetName()));

	}



	auto FoundPlayerTank = GetPlayerTank();
	if (!FoundPlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank not found."));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s sees Player Controller possesing %s."), *(AIControlledTank->GetName()), *(FoundPlayerTank->GetName()));

	}

}

ATank* ATankAIController::GetAIControlledTank() const
{

	//UE_LOG(LogTemp, Warning, TEXT("AIController Get Tank running."));
	return Cast<ATank>(GetPawn());
};


ATank* ATankAIController::GetPlayerTank() const
{
	//UE_LOG(LogTemp, Warning, TEXT("Finding Player Tank..."));
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

