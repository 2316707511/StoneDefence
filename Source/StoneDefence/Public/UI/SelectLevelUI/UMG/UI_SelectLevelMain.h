// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_SelectLevelMain.generated.h"

class UButton;
class UUI_LevelButton;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_SelectLevelMain : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

private:
	UPROPERTY(meta = (BindWidget))
		UButton* ReturnMenuButton;

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* SelectMap;

	TArray<UUI_LevelButton*> AllLevelButton;

protected:
	void InitSelectLevelButton();

	UFUNCTION()
		void ReturnMenu();
};
