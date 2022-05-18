// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM_Character.h"

class AFSM_Character;

/**
 *	@brief CharacterState base class
 */
class FSM_API CharacterState
{
public:
	virtual ~CharacterState() {}
	
	virtual CharacterState* HandleInput(AFSM_Character& Character, UInputComponent* Input) { return new CharacterState; }

	virtual void Start(AFSM_Character& Character) {}
	virtual void Update(AFSM_Character& Character) {}
	virtual void Exit(AFSM_Character& Character) {}
	
	virtual FString GetCurrentStateName() { return "None"; }
};