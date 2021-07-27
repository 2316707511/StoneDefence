// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/MonstersAIController.h"
#include "Character/CharacterCore/Towers.h"
#include "EngineUtils.h"
#include <StoneDefence/StoneDefenceUtils.h>


AActor* AMonstersAIController::FindTarget()
{
	TArray<ARuleOfTheCharacter*> TargetMainTowersArray;
	TArray<ARuleOfTheCharacter*> TargetTowersArray;

	for (TActorIterator<ATowers> it(GetWorld(), ATowers::StaticClass()); it; ++it)
	{
		ATowers* TheCharacter = *it;
		if (TheCharacter && TheCharacter->IsActive())
		{
			if (TheCharacter->GetType() == EGameCharacterType::Type::TOWER)
			{
				TargetTowersArray.Add(TheCharacter);
			}
			else if (TheCharacter->GetType() == EGameCharacterType::Type::MAIN_TOWER)
			{
				TargetTowersArray.Add(TheCharacter);
			}
		}
	}

	ATowers* MainTower = Cast<ATowers>(StoneDefenceUtils::FindTargetRecently(TargetMainTowersArray, GetPawn()->GetActorLocation()));

	if (MainTower)
	{
		return MainTower;
	}

	ATowers* NorTower = Cast<ATowers>(StoneDefenceUtils::FindTargetRecently(TargetTowersArray, GetPawn()->GetActorLocation()));


	return NorTower;
}