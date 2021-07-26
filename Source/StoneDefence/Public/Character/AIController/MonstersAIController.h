// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheAIController.h"
#include "MonstersAIController.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API AMonstersAIController : public ARuleOfTheAIController
{
	GENERATED_BODY()

public:
	virtual AActor* FindTarget() override;
};
