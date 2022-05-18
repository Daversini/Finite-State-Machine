// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM_Character.h"

#include "FSM/FSMGameModeBase.h"
#include "States/Idle_State.h"
#include "States/Jump_State.h"
#include "States/Move_State.h"

// Sets default values
AFSM_Character::AFSM_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	State = new Idle_State;
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

	AFSMGameModeBase::PrintCurrentState(State->GetCurrentStateName());
	State->Update(*this);
}

// Called to bind functionality to input
void AFSM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//Bind Movement
	InputComponent->BindAxis("Horizontal", this, &AFSM_Character::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AFSM_Character::VerticalMove);

	//Bind Rotation
	InputComponent->BindAxis("Pitch", this, &AFSM_Character::RotatePitch);
	InputComponent->BindAxis("Yaw", this, &AFSM_Character::RotateYaw);

	//Bind Actions
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFSM_Character::JumpStart);
	InputComponent->BindAction("Jump", IE_Released, this, &AFSM_Character::JumpEnd);
	//InputComponent->BindAction("Crouch", IE_Pressed, this, &AFSM_Character::HandleInput);
	//InputComponent->BindAction("Crouch", IE_Released, this, &AFSM_Character::HandleInput);
}

void AFSM_Character::HandleInput(UInputComponent* Input)
{
	CharacterState* NewState = State->HandleInput(*this, Input);
	if (NewState != nullptr)
	{
		State->Exit(*this);
		delete State;
		State = NewState;
	}

	State->Start(*this);
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

void AFSM_Character::RotatePitch(float value)
{
	AddControllerPitchInput(value);
}

void AFSM_Character::RotateYaw(float value)
{
	AddControllerYawInput(value);
}

void AFSM_Character::JumpStart()
{
	this->bPressedJump = true;
	State = new Jump_State();
}

void AFSM_Character::JumpEnd()
{
	this->bPressedJump = false;
	State = new Idle_State();
}