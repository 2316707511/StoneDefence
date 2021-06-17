// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_MainScreen.generated.h"

class UUI_GameInfoPrintSystem;
class UUI_GameMenuSystem;
class UUI_MiniMapSystem;
class UUI_MissionSystem;
class UUI_PlayerSkillSystem;
class UUI_RucksackSystem;
class UUI_ToolBarSystem;

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MainScreen : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	
private:
	UPROPERTY(meta = (BindWidget))
		UUI_GameInfoPrintSystem* GameInfoPrintSystem;

	UPROPERTY(meta = (BindWidget))
		UUI_GameMenuSystem* GameMenuSystem;

	UPROPERTY(meta = (BindWidget))
		UUI_MiniMapSystem* MiniMapSystem;

	UPROPERTY(meta = (BindWidget))
		UUI_MissionSystem* MissionSystem;

	UPROPERTY(meta = (BindWidget))
		UUI_PlayerSkillSystem* PlayerSkillSystem;

	UPROPERTY(meta = (BindWidget))
		UUI_RucksackSystem* RucksackSystem;

	UPROPERTY(meta = (BindWidget))
		UUI_ToolBarSystem* ToolBarSystem;
};
