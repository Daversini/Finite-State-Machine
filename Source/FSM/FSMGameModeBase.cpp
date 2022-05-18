// Copyright Epic Games, Inc. All Rights Reserved.


#include "FSMGameModeBase.h"

void AFSMGameModeBase::PrintCurrentState(const FString State)
{
	wchar_t* result = TCHAR_TO_WCHAR(*State);
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, FString::Printf(TEXT("State: %s"), result));
}