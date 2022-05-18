// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterState.h"
#include "FSM_Character.generated.h"

class CharacterState;

UCLASS()
class FSM_API AFSM_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFSM_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void HandleInput(UInputComponent* Input);
	
	void HorizontalMove(float value);
	void VerticalMove(float value);

	void RotatePitch(float value);
	void RotateYaw(float value);

	void JumpStart();
	void JumpEnd();
private:
	CharacterState* State;
};