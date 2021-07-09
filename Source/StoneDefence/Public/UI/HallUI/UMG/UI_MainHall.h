// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_MainHall.generated.h"

class UUI_HallMenuSystem;
class UBorder;
class USizeBox;
class UUI_ArchivesSystem;
class UUI_GameSettingsSystem;
class UUI_TutoriaSystem;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MainHall : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UBorder* MainBoard;

	UPROPERTY(meta = (BindWidget))
	USizeBox* BoxList;

	UPROPERTY(meta = (BindWidget))
	UUI_HallMenuSystem* HallMenuSystem;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<UUI_ArchivesSystem> ArchivesSystemClass;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<UUI_GameSettingsSystem> GameSettingsSystemClass;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<UUI_TutoriaSystem> TutoriaSystemClass;

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
};
