// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_GameInfoPrintSystem.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_GameInfoPrintSystem : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

private:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* TDGameLog;
};
