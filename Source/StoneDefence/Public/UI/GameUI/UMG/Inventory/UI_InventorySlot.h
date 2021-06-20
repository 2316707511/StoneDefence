// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_InventorySlot.generated.h"

class UButton;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_InventorySlot : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

	UFUNCTION()
	void OnClickedWidget();
private:

	UPROPERTY(meta = (BindWidget))
		UImage*	TowersIcon;

	UPROPERTY(meta = (BindWidget))
		UImage* TowersCD;

	//Towers Prepare Building
	UPROPERTY(meta = (BindWidget))
		UTextBlock* TPBNumber;

	//Towers Completion Of Construction Number
	UPROPERTY(meta = (BindWidget))
		UTextBlock* TCOCNumber;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* TowersCDValue;

	//Towers Inventory Slot Button
	UPROPERTY(meta = (BindWidget))
		UButton* TISButton;
};
