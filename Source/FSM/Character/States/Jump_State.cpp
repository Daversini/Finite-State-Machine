// Fill out your copyright notice in the Description page of Project Settings.


#include "Jump_State.h"

Jump_State::Jump_State()
{
}

Jump_State::~Jump_State()
{
}

CharacterState* Jump_State::HandleInput(AFSM_Character& Character, UInputComponent* Input)
{
	return nullptr;
}

void Jump_State::Start(AFSM_Character& Character)
{
	Character.bPressedJump = true;
}

void Jump_State::Update(AFSM_Character& Character)
{
	CharacterState::Update(Character);
}

void Jump_State::Exit(AFSM_Character& Character)
{
	Character.bPressedJump = false;
}