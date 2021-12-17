// Copyright Epic Games, Inc. All Rights Reserved.

#include "Jogo2DGameMode.h"
#include "Jogo2DCharacter.h"

AJogo2DGameMode::AJogo2DGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AJogo2DCharacter::StaticClass();	
}
