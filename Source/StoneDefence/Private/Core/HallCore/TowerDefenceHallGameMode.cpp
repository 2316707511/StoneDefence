// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/HallCore/TowerDefenceHallGameMode.h"
#include "UI/HallUI/Core/TowerDefenceHallHUD.h"
#include "Core/HallCore/TowersDefenceHallPawn.h"
#include "Core/HallCore/TowerDefenceHallPlayerController.h"

ATowerDefenceHallGameMode::ATowerDefenceHallGameMode()
{
	HUDClass = ATowerDefenceHallHUD::StaticClass();
	PlayerControllerClass = ATowerDefenceHallPlayerController::StaticClass();
	DefaultPawnClass = ATowersDefenceHallPawn::StaticClass();
}