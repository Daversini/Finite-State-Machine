// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_State.h"

Move_State::Move_State()
{
}

Move_State::~Move_State()
{
}

CharacterState* Move_State::HandleInput(AFSM_Character& Character, UInputComponent* Input)
{
	return nullptr;
}

void Move_State::Start(AFSM_Character& Character)
{
	CharacterState::Start(Character);
}

void Move_State::Update(AFSM_Character& Character)
{
	CharacterState::Update(Character);
}

void Move_State::Exit(AFSM_Character& Character)
{
	CharacterState::Exit(Character);
}