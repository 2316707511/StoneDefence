#include "Tool\ScreenMove.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

bool FScreenMoveUnits::ListenScreenMove(const APlayerController* PlayerController, const float& ScreenMoveSpeed)
{
	return MoveDirection(PlayerController, CursorMove(PlayerController), ScreenMoveSpeed);
}

EScreenMoveState FScreenMoveUnits::CursorMove(const APlayerController* PlayerController)
{
	if (!PlayerController)
	{
		return EScreenMoveState::Screen_None;
	}

	int32 SizeX = INDEX_NONE;
	int32 SizeY = INDEX_NONE;

	float MousePositionX = 0.f;
	float MousePositionY = 0.f;

	PlayerController->GetViewportSize(SizeX, SizeY);
	PlayerController->GetMousePosition(MousePositionX, MousePositionY);

	if (MousePositionX >= 0 && MousePositionX <= SizeX &&
		MousePositionY >= 0 && MousePositionY <= SizeY)
	{
		if (FMath::IsNearlyEqual(MousePositionX, 0.f, 5.f))
		{
			if (FMath::IsNearlyEqual(MousePositionY, 0.f, 5.f))
			{
				return EScreenMoveState::Screen_LeftAndUP;
			}
			if (FMath::IsNearlyEqual(MousePositionY, SizeY, 5.f))
			{
				return EScreenMoveState::Screen_LeftAndDown;
			}
			return EScreenMoveState::Screen_Left;
		}
		else if (FMath::IsNearlyEqual(MousePositionX, SizeX, 5.f))
		{
			if (FMath::IsNearlyEqual(MousePositionY, 0.f, 5.f))
			{
				return EScreenMoveState::Screen_RightAndUP;
			}
			if (FMath::IsNearlyEqual(MousePositionY, SizeY, 5.f))
			{
				return EScreenMoveState::Screen_RightAndDown;
			} 
			return EScreenMoveState::Screen_Right;
		}
		else
		{
			if (FMath::IsNearlyEqual(MousePositionY, 0.f, 5.f))
			{
				return EScreenMoveState::Screen_UP;
			}
			if (FMath::IsNearlyEqual(MousePositionY, SizeY, 5.f))
			{
				return EScreenMoveState::Screen_Down;
			}
		}
	}
	return EScreenMoveState::Screen_None;
}

bool FScreenMoveUnits::MoveDirection(const APlayerController* PlayerController, EScreenMoveState ScreenMoveState, const float& ScreenMoveSpeed)
{
	FVector OffsetValue = FVector::ZeroVector;
	if (PlayerController &&
		PlayerController->GetPawn())
	{
		switch (ScreenMoveState)
		{
		case Screen_UP:
			OffsetValue = FVector(ScreenMoveSpeed, 0.f, 0.f);
			break;
		case Screen_Down:
			OffsetValue = FVector(-ScreenMoveSpeed, 0.f, 0.f);
			break;
		case Screen_Right:
			OffsetValue = FVector(0.f, ScreenMoveSpeed, 0.f);
			break;
		case Screen_Left:
			OffsetValue = FVector(0.f, -ScreenMoveSpeed, 0.f);
			break;
		case Screen_RightAndUP:
			OffsetValue = FVector(ScreenMoveSpeed, ScreenMoveSpeed, 0.f);
			break;
		case Screen_RightAndDown:
			OffsetValue = FVector(-ScreenMoveSpeed, ScreenMoveSpeed, 0.f);
			break;
		case Screen_LeftAndUP:
			OffsetValue = FVector(ScreenMoveSpeed, -ScreenMoveSpeed, 0.f);
			break;
		case Screen_LeftAndDown:
			OffsetValue = FVector(-ScreenMoveSpeed, -ScreenMoveSpeed, 0.f);
			break;
		}
		PlayerController->GetPawn()->AddActorWorldOffset(OffsetValue);
	}

	return OffsetValue != FVector::ZeroVector;
}
