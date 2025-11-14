// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_UpdateTargetLoc.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTService_UpdateTargetLoc : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_UpdateTargetLoc();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetLocationKey; 
};