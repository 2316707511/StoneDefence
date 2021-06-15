// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tool/ScreenMove.h"
#include "TowerDefencePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefencePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATowerDefencePlayerController();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	void SetInputModeGameAndUI();

	//允许玩家自己更新自己的绑定响应
	virtual void SetupInputComponent() override;

	void MouseWheelUp();

	void MouseWheelDown();

protected:
	FScreenMoveUnits ScreenMoveUnits;
};
