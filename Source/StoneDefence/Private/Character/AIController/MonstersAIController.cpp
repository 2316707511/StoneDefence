// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/MonstersAIController.h"
#include "Character/CharacterCore/Towers.h"
#include "EngineUtils.h"


AActor* AMonstersAIController::FindTarget()
{
	auto GetRecentlyTowers = [&](const TArray<ATowers*>& MyTowers) -> ATowers*
	{
		if (MyTowers.Num())
		{
			float TowerTargetDistance = 99999999;
			int32 TowersIndex = INDEX_NONE;
			FVector MyLocation = GetPawn()->GetActorLocation();
			for (int32 i = 0; i < MyTowers.Num(); ++i)
			{
				if (ATowers* TowerCharacter = MyTowers[i])
				{
					FVector TowerLocation = TowerCharacter->GetActorLocation();
					FVector TmpVector = TowerLocation - MyLocation;
					float TowerAndMonsterDistance = TmpVector.Size();

					if (TowerAndMonsterDistance < TowerTargetDistance)
					{
						TowersIndex = i;
						TowerTargetDistance = TowerAndMonsterDistance;
					}
				}
			}

			if (TowersIndex != INDEX_NONE)
			{
				return MyTowers[TowersIndex];
			}
		}

		return nullptr;
	};

	TArray<ATowers*> TargetMainTowersArray;
	TArray<ATowers*> TargetTowersArray;

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

	ATowers* MainTower = GetRecentlyTowers(TargetMainTowersArray);

	if (MainTower)
	{
		return MainTower;
	}

	ATowers* NorTower = GetRecentlyTowers(TargetTowersArray);


	return NorTower;
}