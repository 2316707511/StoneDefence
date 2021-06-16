// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/SelectLevelCore/TowersDefenceSelectLevelGameMode.h"
#include "UI/SelectLevelUI/Core/TowersDefenceSelectLevelHUD.h"


ATowersDefenceSelectLevelGameMode::ATowersDefenceSelectLevelGameMode()
{
	HUDClass = ATowersDefenceSelectLevelHUD::StaticClass();
}

void ATowersDefenceSelectLevelGameMode::BeginPlay()
{
}
