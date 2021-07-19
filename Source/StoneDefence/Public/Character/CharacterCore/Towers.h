// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Towers.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
class UDestructibleComponent;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowers : public ARuleOfTheCharacter
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	ATowers();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* StaticMeshBuilding;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	UDestructibleComponent* DestructibleMeshBuilding;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	UParticleSystemComponent* ParticleMesh;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute")
	FRotator TowersRotator;
};
