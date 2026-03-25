// Fill out your copyright notice in the Description page of Project Settings.


#include "ASPowerUpActor.h"
#include "Components/SphereComponent.h"

// Sets default values
AASPowerUpActor::AASPowerUpActor()
{
	sphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	sphereComp->SetCollisionProfileName("PowerUp");
	RootComponent = sphereComp;

	RespawnTime = 10.0f;
}

void AASPowerUpActor::Interact_Implementation(APawn* InstigatorPawn)
{
	//logic in derived classes...
}

void AASPowerUpActor::ShowPowerup()
{
	SetPowerupState(true);
}

void AASPowerUpActor::HideAndCooldownPowerup()
{
	SetPowerupState(false);

	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &AASPowerUpActor::ShowPowerup, RespawnTime);
}

void AASPowerUpActor::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);

	// Set visibility on root and all children
	RootComponent->SetVisibility(bNewIsActive, true);
}