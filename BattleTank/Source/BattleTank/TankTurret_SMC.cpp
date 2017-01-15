// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret_SMC.h"



void UTankTurret_SMC::Rotate(float RelativeRotSpeed)
{
	auto ClampedRelativeRotSpeed = FMath::Clamp<float>(RelativeRotSpeed, -1, 1);
	auto RotationChange = ClampedRelativeRotSpeed * MaxRotDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));

}
