// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_MainHall.generated.h"

class UUI_HallMenuSystem;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MainHall : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UUI_HallMenuSystem* HallMenuSystem;

public:
	virtual void NativeConstruct();
};
