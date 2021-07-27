// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BTService/BTService_MonsterFindTarget.h"
#include "Character/AIController/MonstersAIController.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


void UBTService_MonsterFindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AMonstersAIController* MonsterAIController = Cast<AMonstersAIController>(OwnerComp.GetOwner());
	if (!MonsterAIController)
	{
		return;
	}

	UBlackboardComponent* MyBlackBoard = OwnerComp.GetBlackboardComponent();
	if (!MyBlackBoard)
	{
		return;
	}


	//Set Target
	ARuleOfTheCharacter* NewTarget = Cast<ARuleOfTheCharacter>(MonsterAIController->FindTarget());
	if (!NewTarget)
	{
		return;
	}
	else
	{
		if (Target != NewTarget)
		{
			if (ARuleOfTheCharacter* MonsterSelf = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn()))
			{
				MonsterSelf->GetCharacterMovement()->StopMovementImmediately();
			}
			Target = NewTarget;
		}

		if (Target.IsValid())
		{
			if (Target->IsActive())
			{
				MyBlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, Target.Get());
				MyBlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, Target.Get()->GetActorLocation());
			}
			else
			{
				MyBlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, NULL);
				MyBlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, FVector::ZeroVector);
			}
		}
		else
		{
			MyBlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, NULL);
			MyBlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, FVector::ZeroVector);
		}
	}

	//Set Distance
	if (Target.IsValid())
	{
		FVector MyLocation = MonsterAIController->GetPawn()->GetActorLocation();
		FVector TMDistance = MyLocation - Target->GetActorLocation();
		if (TMDistance.Size() > 2200)
		{
			if (ARuleOfTheCharacter* MonsterAI = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn()))
			{
				MonsterAI->bAttack = false;
			}
		}

		MyBlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, TMDistance.Size());
	}
	else
	{
		MyBlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, 0.f);
	}
}
