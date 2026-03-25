// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ASPowerUpActor.h"
#include "SPowerup_HealthPotion.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPowerup_HealthPotion : public AASPowerUpActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

public:

	void Interact_Implementation(APawn* InstigatorPawn) override;

	ASPowerup_HealthPotion();
};
