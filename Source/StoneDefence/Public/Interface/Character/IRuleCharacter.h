#pragma once

#include "CoreMinimal.h"
#include <StoneDefence/StoneDefenceType.h>

class IRuleCharacter
{
public:

	virtual bool IsDeath() = 0;
	virtual float GetHealth() = 0;
	virtual float GetMaxHealth() = 0;
	virtual bool IsTeam() = 0;
	virtual EGameCharacterType::Type GetType() = 0;
};