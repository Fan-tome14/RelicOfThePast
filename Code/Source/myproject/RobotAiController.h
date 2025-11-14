// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
// Headers nécessaires pour les composants Behavior Tree et Blackboard
#include "BehaviorTree/BehaviorTreeComponent.h" 
#include "BehaviorTree/BlackboardComponent.h"
#include "RobotAiController.generated.h"

class ARobotCharacter; 

UCLASS()
class MYPROJECT_API ARobotAiController : public AAIController
{
	GENERATED_BODY()
    
public:
	ARobotAiController();
    
protected:
	// Surcharges des événements de possession automatiques
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
    
private:
	// Les composants de l'IA
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBlackboardComponent* BlackboardComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTreeComponent* BehaviorTreeComponent;
    
	// Nom de la clé qui stocke la référence du joueur dans le Blackboard
	UPROPERTY(EditAnywhere, Category = "AI")
	FName TargetActorKey = "TargetActor";
};