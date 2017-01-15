// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret_SMC.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret_SMC : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Rotate(float RelativeRotSpeed);


private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotDegreesPerSecond = 5;
	
};
