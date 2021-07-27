// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/TowersAIController.h"
#include "Character/CharacterCore/Towers.h"
#include "Character/CharacterCore/Monsters.h"
#include "EngineUtils.h"
#include <StoneDefence/StoneDefenceUtils.h>

ATowersAIController::ATowersAIController()
    :HeartbeatDiagnosis(0.0f)
{

}

void ATowersAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    HeartbeatDiagnosis += DeltaTime;
    if (HeartbeatDiagnosis >= 0.5f)
    {
        BTService_FindTarget();
        HeartbeatDiagnosis = 0.f;
    }

    if (TArrayMonsters.Num())
    {
        if (ATowers* Tower = GetPawn<ATowers>())
        {
            Target = Cast<ARuleOfTheCharacter>(FindTarget());

            if (Target.IsValid())
            {
                Tower->TowersRotator = FRotationMatrix::MakeFromX( Target->GetActorLocation() - GetPawn()->GetActorLocation()).Rotator();

                if (GetPawn()->GetActorRotation() != FRotator::ZeroRotator)
                {
                    Tower->TowersRotator -= GetPawn()->GetActorRotation();
                }
            }
        }
    }
}

AActor* ATowersAIController::FindTarget()
{
    if (TArrayMonsters.Num())
    {
        return StoneDefenceUtils::FindTargetRecently(TArrayMonsters, GetPawn()->GetActorLocation());
    }
    return nullptr;
}

void ATowersAIController::BTService_FindTarget()
{
    TArrayMonsters.Empty();

    ATowers* Tower = GetPawn<ATowers>();
    if (!Tower)
    {
        return;
    }
    if (!Tower->IsActive())
    {
        return;
    }

    for (TActorIterator<AMonsters> it(GetWorld(), AMonsters::StaticClass()); it; ++it)
    {
        if (AMonsters* TheMonster = *it)
        {
            if (TheMonster->IsActive())
            {
                FVector TDistance = TheMonster->GetActorLocation() - GetPawn()->GetActorLocation();
                if (TDistance.Size() <= 1600)
                {
                    TArrayMonsters.Add(TheMonster);
                }
            }
        }
    }

    if (TArrayMonsters.Num())
    {
        Tower->bAttack = true;
    }
    else
    {
        Tower->bAttack = false;
    }

}
