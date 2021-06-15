// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefencePlayerController.h"
#include "Core/GameCore/TowerDefenceGameCamera.h"

ATowerDefencePlayerController::ATowerDefencePlayerController()
{
	bShowMouseCursor = true;
	UE_LOG(LogTemp, Log, TEXT("ATowerDefencePlayerController::ATowerDefencePlayerController"));
}

void ATowerDefencePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	float ScreenMoveSpeed = 20.f;
	ScreenMoveUnits.ListenScreenMove(this, ScreenMoveSpeed);
}

void ATowerDefencePlayerController::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("ATowerDefencePlayerController::BeginPlay"));
	Super::BeginPlay();
	SetInputModeGameAndUI();

}

void ATowerDefencePlayerController::SetInputModeGameAndUI()
{
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);
}

void ATowerDefencePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseWheelUp", IE_Pressed, this, &ATowerDefencePlayerController::MouseWheelUp);
	InputComponent->BindAction("MouseWheelDown", IE_Pressed, this, &ATowerDefencePlayerController::MouseWheelDown);
}


static float WheelValue = 15.f;
void ATowerDefencePlayerController::MouseWheelUp()
{
	ATowerDefenceGameCamera* ZoomCamera = Cast<ATowerDefenceGameCamera>(GetPawn());
	if (!ZoomCamera)
	{
		return;
	}
	ZoomCamera->Zoom(true, WheelValue);
}

void ATowerDefencePlayerController::MouseWheelDown()
{
	ATowerDefenceGameCamera* ZoomCamera = Cast<ATowerDefenceGameCamera>(GetPawn());
	if (!ZoomCamera)
	{
		return;
	}
	ZoomCamera->Zoom(false, WheelValue);
}
