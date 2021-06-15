// Copyright Epic Games, Inc. All Rights Reserved.


#include "StoneDefenceGameModeBase.h"
#include "Core/GameCore/TowerDefenceGameCamera.h"
#include "Core/GameCore/TowerDefencePlayerController.h"
#include "Core/GameCore/TowerDefencePlayerState.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "UI/GameUI/Core/RuleOfTheHUD.h"

AStoneDefenceGameModeBase::AStoneDefenceGameModeBase()
{
	DefaultPawnClass = ATowerDefenceGameCamera::StaticClass();
	HUDClass = ARuleOfTheHUD::StaticClass();
	PlayerControllerClass = ATowerDefencePlayerController::StaticClass();
	GameStateClass = ATowerDefenceGameState::StaticClass();
	PlayerStateClass = ATowerDefencePlayerState::StaticClass();
}