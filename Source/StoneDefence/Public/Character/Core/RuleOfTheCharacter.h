// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/Character/IRuleCharacter.h"
#include "Core/GameCore/TowerDefencePlayerController.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "RuleOfTheCharacter.generated.h"

class UBoxComponent;
class UArrowComponent;
class USceneComponent;
class UWidgetComponent;

UCLASS()
class STONEDEFENCE_API ARuleOfTheCharacter : public ACharacter, public IRuleCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARuleOfTheCharacter();

	virtual void Tick(float DeltaTime) override;

	FORCEINLINE ATowerDefencePlayerController* GetGameController() {
		return GetWorld() ? GetWorld()->GetFirstPlayerController<ATowerDefencePlayerController>(): nullptr;
	}

	FORCEINLINE ATowerDefenceGameState* GetGameState() {
		return GetWorld() ? GetWorld()->GetGameState<ATowerDefenceGameState>() : nullptr;
	}

	FORCEINLINE USceneComponent* GetHomingPoint() const{
		return HomingPoint;
	}

	FORCEINLINE UArrowComponent* GetFirePoint() const {
		return OpenFirePoint;
	}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual bool IsDeath() override;

	virtual float GetHealth() override;

	virtual float GetMaxHealth() override;

	virtual bool IsTeam() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	USceneComponent* HomingPoint;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	UWidgetComponent* Widget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	UArrowComponent* OpenFirePoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	UBoxComponent* TraceShowCharacterInformation;

};
