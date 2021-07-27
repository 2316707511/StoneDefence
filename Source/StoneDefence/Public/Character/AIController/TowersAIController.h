// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheAIController.h"
#include "TowersAIController.generated.h"

class ARuleOfTheCharacter;

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowersAIController : public ARuleOfTheAIController
{
	GENERATED_BODY()
public:
	ATowersAIController();

	virtual void Tick(float DeltaTime) override;

	virtual AActor* FindTarget();

protected:
	void BTService_FindTarget();

protected:

	UPROPERTY()
	TArray<ARuleOfTheCharacter*> TArrayMonsters;

	TWeakObjectPtr<ARuleOfTheCharacter> Target;

	float HeartbeatDiagnosis;
};
