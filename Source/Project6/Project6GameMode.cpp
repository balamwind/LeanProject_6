// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project6GameMode.h"
#include "Project6Character.h"
#include "UObject/ConstructorHelpers.h"

AProject6GameMode::AProject6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
