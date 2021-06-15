#pragma once

#include "CoreMinimal.h"

class APlayerController;

enum EScreenMoveState
{
	Screen_None,
	Screen_UP,
	Screen_Down,
	Screen_Right,
	Screen_Left,
	Screen_RightAndUP,
	Screen_RightAndDown,
	Screen_LeftAndUP,
	Screen_LeftAndDown,
	Screen_Max
};

struct STONETOOLCLASS_API FScreenMoveUnits
{
	bool ListenScreenMove(const APlayerController* PlayerController, const float &ScreenMoveSpeed = 100.f);

protected:
	/**
	* 获取当前移动状态
	* @param PlayerController	玩家的控制
	* @return					返回当前捕捉的状态
	*/
	EScreenMoveState CursorMove(const APlayerController* PlayerController);

	/**
	* 是当前的Pawn随着鼠标移动
	* @param PlayerController	玩家的控制
	* @param ScreenMoveState	移动状态
	* @param ScreenMoveSpeed	屏幕移动速度
	* @return					返回当前是否移动成功
	*/
	bool MoveDirection(const APlayerController* PlayerController, EScreenMoveState ScreenMoveState, const float &ScreenMoveSpeed);
};