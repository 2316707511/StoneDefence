// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_HallMenuSystem.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_HallMenuSystem : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();

	UFUNCTION()
	void GameStart();
	UFUNCTION()
	void History();
	UFUNCTION()
	void GameSettings();
	UFUNCTION()
	void TutorialWebsite();
	UFUNCTION()
	void Browser();
	UFUNCTION()
	void QuitGame();
	UFUNCTION()
	void SecretTerritory();
	UFUNCTION()
	void SpecialContent();

private:
	UPROPERTY(meta = (BindWidget))
		UButton* GameStartButton;

	UPROPERTY(meta = (BindWidget))
		UButton* HistoryButton;

	UPROPERTY(meta = (BindWidget))
		UButton* GameSettingsButton;

	UPROPERTY(meta = (BindWidget))
		UButton* TutorialWebsiteButton;

	UPROPERTY(meta = (BindWidget))
		UButton* BrowserButton;

	UPROPERTY(meta = (BindWidget))
		UButton* QuitGameButton;

	UPROPERTY(meta = (BindWidget))
		UButton* SecretTerritoryButton;

	UPROPERTY(meta = (BindWidget))
		UButton* SpecialContentButton;
};
