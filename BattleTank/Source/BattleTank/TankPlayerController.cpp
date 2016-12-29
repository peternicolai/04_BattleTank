// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Contoller Begin Play"));

	ATankPlayerController::GetControlledTank();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Get Tank running.")); 
	//UE_LOG(LogTemp, Warning, TEXT("Possessed Pawn is %s"), *GetOwner()->GetName());
	return Cast<ATank>(GetPawn());
};
//
//FString Objectname = GetOwner()->GetName();
//FString ObjectPos = GetOwner()->GetActorLocation().ToString();
//UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *Objectname, *ObjectPos);
