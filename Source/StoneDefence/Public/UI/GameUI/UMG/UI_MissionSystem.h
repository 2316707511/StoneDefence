// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_MissionSystem.generated.h"

class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MissionSystem : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

private:
	UFUNCTION()
		void Condition();

private:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* ConditionBase;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* ConditionA;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* ConditionB;

	UPROPERTY(meta = (BindWidget))
		UButton* ConditionButton;

};
