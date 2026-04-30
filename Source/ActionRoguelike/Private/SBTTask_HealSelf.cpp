// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTTask_HealSelf.h"
#include "SAttributeComponent.h"
#include "AIController.h"



USBTTask_HealSelf::USBTTask_HealSelf()
{
	NodeName = "Heal Self";
}

EBTNodeResult::Type USBTTask_HealSelf::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController = OwnerComp.GetAIOwner();
	if (!ensure(MyController))
	{
		return EBTNodeResult::Failed;
	}

	APawn* MyPawn = MyController->GetPawn();
	if (MyPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(MyPawn);
	if (ensure(AttributeComp))
	{
		AttributeComp->ApplyHealthChange(MyPawn, AttributeComp->GetHealthMax());
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
