// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "HumanCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHumanCharacter : public AMyCharacter
{
	GENERATED_BODY()
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void ToggleRobotFollowing();
};
