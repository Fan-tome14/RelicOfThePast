// Fill out your copyright notice in the Description page of Project Settings.


#include "HumanCharacter.h"

void AHumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	// Boost Speed
	PlayerInputComponent->BindAction("BoostSpeed", IE_Pressed, this, &AMyCharacter::BoostSpeed);
	PlayerInputComponent->BindAction("BoostSpeed", IE_Released, this, &AMyCharacter::RemoveSpeedBoost);

}
