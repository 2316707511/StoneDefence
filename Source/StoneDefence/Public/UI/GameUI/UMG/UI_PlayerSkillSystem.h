// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_PlayerSkillSystem.generated.h"

class UUI_SkillSlot;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_PlayerSkillSystem : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();

private:
	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* FreezeSkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* ExplosionSkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* RecoverySkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* RecoveryMainTowersSkill;
};
