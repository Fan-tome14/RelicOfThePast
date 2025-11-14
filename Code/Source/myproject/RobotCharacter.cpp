// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotCharacter.h"

#include "RobotAiController.h"


ARobotCharacter::ARobotCharacter()
{
	// Activation du Tick pour le Pawn si nécessaire
	PrimaryActorTick.bCanEverTick = true; 
}

void ARobotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ARobotCharacter::BeginPlay()
{
	Super::BeginPlay();

	ARobotAiController* RobotController = Cast<ARobotAiController>(GetController());
            
	if (RobotController)
	{
		UBlackboardComponent* BlackboardComp = RobotController->GetBlackboardComponent();
                
		if (BlackboardComp)
		{

			BlackboardComp->SetValueAsBool("IsFollowing", true);
		}

	}
}