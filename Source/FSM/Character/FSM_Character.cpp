// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM_Character.h"

// Sets default values
AFSM_Character::AFSM_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AFSM_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFSM_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UPDATE
}

// Called to bind functionality to input
void AFSM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &AFSM_Character::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AFSM_Character::VerticalMove);
}

void AFSM_Character::handleInput()
{
	//ROBBBBA
}

void AFSM_Character::HorizontalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AFSM_Character::VerticalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}