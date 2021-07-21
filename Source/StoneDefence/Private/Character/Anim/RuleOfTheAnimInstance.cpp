// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Anim/RuleOfTheAnimInstance.h"
#include "Character/Core/RuleOfTheCharacter.h"

URuleOfTheAnimInstance::URuleOfTheAnimInstance()
	:bDeath(false)
	,bAttack(false)
	,Speed(0.0f)
{

}

void URuleOfTheAnimInstance::NativeInitializeAnimation()
{

}

void URuleOfTheAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	ARuleOfTheCharacter* RuleOfTheCharacter = Cast<ARuleOfTheCharacter>(TryGetPawnOwner());
	if (!RuleOfTheCharacter)
	{
		return;
	}
	bAttack = RuleOfTheCharacter->bAttack;
	bDeath = !RuleOfTheCharacter->IsActive();
	Speed = RuleOfTheCharacter->GetVelocity().Size();
}


