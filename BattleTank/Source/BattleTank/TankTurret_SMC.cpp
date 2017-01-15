// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret_SMC.h"



void UTankTurret_SMC::Rotate(float RelativeRotSpeed)
{


	//move the barrel given max elev speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("Turret-Rotate() Called at speed %f"), RelativeRotSpeed);


	//auto ClampedRelativeRotSpeed = FMath::Clamp<float>(RelativeRotSpeed, -1, 1);
	auto RotationChange = RelativeRotSpeed * MaxRotDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	//auto ClampedNewRotation = FMath::Clamp<float>(RawNewRotation, 0, MaxRotDegreesPerSecond);

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));

}
