// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CharacterState.h"

/**
 * 
 */
class FSM_API Move_State : public CharacterState
{
public:
	Move_State();
	~Move_State();

	virtual CharacterState* HandleInput(AFSM_Character& Character, UInputComponent* Input) override;
	
	virtual void Start(AFSM_Character& Character) override;
	virtual void Update(AFSM_Character& Character) override;
	virtual void Exit(AFSM_Character& Character) override;

	virtual FString GetCurrentStateName() override { return "Move"; }
};