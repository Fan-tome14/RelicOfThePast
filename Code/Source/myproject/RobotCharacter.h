// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "RobotCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ARobotCharacter : public AMyCharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	UBehaviorTree* BehaviorTree;
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
