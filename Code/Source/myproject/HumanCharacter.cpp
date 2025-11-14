// Fill out your copyright notice in the Description page of Project Settings.


#include "HumanCharacter.h"

#include "RobotAiController.h"
#include "RobotCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AHumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	// Boost Speed
	PlayerInputComponent->BindAction("BoostSpeed", IE_Pressed, this, &AMyCharacter::BoostSpeed);
	PlayerInputComponent->BindAction("BoostSpeed", IE_Released, this, &AMyCharacter::RemoveSpeedBoost);

	PlayerInputComponent->BindAction("Follow", IE_Pressed, this, &AHumanCharacter::ToggleRobotFollowing);
}

void AHumanCharacter::ToggleRobotFollowing()
{
    ARobotCharacter* TargetRobot = Cast<ARobotCharacter>(
        UGameplayStatics::GetActorOfClass(GetWorld(), ARobotCharacter::StaticClass())
    );

    if (TargetRobot)
    {
        ARobotAiController* RobotController = Cast<ARobotAiController>(TargetRobot->GetController());

        if (RobotController)
        {
            UBlackboardComponent* BlackboardComp = RobotController->GetBlackboardComponent();
            
            if (BlackboardComp)
            {
                const FName KeyName("IsFollowing");
            	bool bCurrentValue = BlackboardComp->GetValueAsBool(KeyName);
                bool bNewValue = !bCurrentValue;
            	BlackboardComp->SetValueAsBool(KeyName, bNewValue);

                UE_LOG(LogTemp, Warning, TEXT("Robot Follow status toggled to: %s"), bNewValue ? TEXT("TRUE") : TEXT("FALSE"));
            }
        }
    }
}