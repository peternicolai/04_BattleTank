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


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller ticking."));
	if (GetPlayerTank())
	{
		//TODO move to player
		AimTowardsPlayer();
	}
	return;
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




void ATankAIController::AimTowardsPlayer()
{
	if (!GetAIControlledTank()) { return; }
	{
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}