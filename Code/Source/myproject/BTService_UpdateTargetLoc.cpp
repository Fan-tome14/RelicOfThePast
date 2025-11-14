// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateTargetLoc.h"

#include "HumanCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_UpdateTargetLoc::UBTService_UpdateTargetLoc() 
{
	NodeName = TEXT("Update Target Location");
     
}

void UBTService_UpdateTargetLoc::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return;
 	
	AActor* TargetActor = UGameplayStatics::GetActorOfClass(GetWorld(), AHumanCharacter::StaticClass());
	if (TargetActor)
	{
		BlackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, TargetActor->GetActorLocation());
	}
}