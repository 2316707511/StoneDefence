// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_LevelButton.generated.h"

class UBorder;
class UProgressBar;
class UButton;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_LevelButton : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
		UBorder* LevelBorder;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* LevelProBar;

	UPROPERTY(meta = (BindWidget))
		UButton* NextLevelButton;
public:
	virtual void NativeConstruct();

	UFUNCTION()
	void SelectLevel();
	
};
