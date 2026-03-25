// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGamePlayInterface.h"
#include "ASPowerUpActor.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API AASPowerUpActor : public AActor, public ISGamePlayInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Powerup")
	float RespawnTime;

	FTimerHandle TimerHandle_RespawnTimer;
	
	UFUNCTION()
	void ShowPowerup();

	void HideAndCooldownPowerup();

	void SetPowerupState(bool bNewIsActive);

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* sphereComp;

public:

	void Interact_Implementation(APawn* InstigatorPawn) override;

public:	
	
	AASPowerUpActor();
};
