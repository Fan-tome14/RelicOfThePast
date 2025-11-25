// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotAiController.h"

#include "RobotCharacter.h"


// Sets default values
ARobotAiController::ARobotAiController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void ARobotAiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
    
	ARobotCharacter* RobotCharacter = Cast<ARobotCharacter>(InPawn);
	if (RobotCharacter && RobotCharacter->BehaviorTree)
	{
		// Démarre l'exécution du Behavior Tree
		if (RobotCharacter->BehaviorTree->BlackboardAsset)
		{
			UseBlackboard(RobotCharacter->BehaviorTree->BlackboardAsset, BlackboardComponent);
			RunBehaviorTree(RobotCharacter->BehaviorTree);
		}
	}
}


void ARobotAiController::OnUnPossess()
{
	Super::OnUnPossess();
    
	if (BehaviorTreeComponent && BehaviorTreeComponent->IsRunning())
	{
		BehaviorTreeComponent->StopTree();
	}
}