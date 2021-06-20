// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_SkillSlot.generated.h"

class UImage;
class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_SkillSlot : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

	UFUNCTION()
	void OnClickedWidget();

private:
	UPROPERTY(meta = (BindWidget))
		UImage* SkillIcon;
	
	UPROPERTY(meta = (BindWidget))
		UImage* SkillIconCD;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* SkillNumber;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* KeyValueNumber;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* SkillCDValue;

	UPROPERTY(meta = (BindWidget))
		UButton* ClickButton;
};
