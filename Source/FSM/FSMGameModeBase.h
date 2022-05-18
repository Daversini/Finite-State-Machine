// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FSMGameModeBase.generated.h"

/**
 *	@brief FSM GameMode base class
 */
UCLASS()
class FSM_API AFSMGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "FSM")
	static void PrintCurrentState(const FString State);
};