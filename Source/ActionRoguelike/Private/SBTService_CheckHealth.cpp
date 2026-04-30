// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTService_CheckHealth.h"
#include "SAttributeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

USBTService_CheckHealth::USBTService_CheckHealth()
{
	NodeName = "Check Health";
	LowHealthFraction = 0.3f;
}

void USBTService_CheckHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* MyController = OwnerComp.GetAIOwner();
	if (ensure(MyController))
	{
		APawn* AIPawn = MyController->GetPawn();
		if (ensure(AIPawn))
		{
			USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(AIPawn);
			if (ensure(AttributeComp))
			{
				bool bLowHealth = (AttributeComp->GetHealth() / AttributeComp->GetHealthMax()) <= LowHealthFraction;

				UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
				BlackboardComp->SetValueAsBool(LowHealthKey.SelectedKeyName, bLowHealth);
			}
		}
	}
}
