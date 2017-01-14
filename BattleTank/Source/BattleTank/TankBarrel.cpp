// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//move the barrel given max elev speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() Called at speed %f"), DegreesPerSecond);
}
