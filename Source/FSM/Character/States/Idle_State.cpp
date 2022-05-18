// Fill out your copyright notice in the Description page of Project Settings.


#include "Idle_State.h"

#include "Jump_State.h"

Idle_State::Idle_State()
{
}

Idle_State::~Idle_State()
{
}

CharacterState* Idle_State::HandleInput(AFSM_Character& Character, UInputComponent* Input)
{
	if (Input->GetAxisValue("Jump") == 1.0f)
	{
		Character.JumpStart();

		return new Jump_State;
	}
	
	return nullptr;
}

void Idle_State::Start(AFSM_Character& Character)
{
	CharacterState::Start(Character);
}

void Idle_State::Update(AFSM_Character& Character)
{
	CharacterState::Update(Character);
}

void Idle_State::Exit(AFSM_Character& Character)
{
	CharacterState::Exit(Character);
}