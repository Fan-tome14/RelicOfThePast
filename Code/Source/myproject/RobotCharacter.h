// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h" // Assurez-vous que MyCharacter existe
#include "BehaviorTree/BehaviorTree.h"
#include "RobotCharacter.generated.h"

UCLASS()
class MYPROJECT_API ARobotCharacter : public AMyCharacter
{
	GENERATED_BODY()
    
public:
	ARobotCharacter();

	// La propriété qui contiendra l'asset de votre Behavior Tree
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	UBehaviorTree* BehaviorTree;

protected:
	// Surcharge de la gestion des entrées (input)
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void BeginPlay();
};