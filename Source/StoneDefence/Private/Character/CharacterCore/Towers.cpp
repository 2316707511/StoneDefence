// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterCore/Towers.h"
#include "DestructibleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"

float ATowers::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	return 0.0f;
}

ATowers::ATowers()
{
	StaticMeshBuilding = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RangeBuilding"));
	DestructibleMeshBuilding = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Substitute"));
	ParticleMesh = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleMesh"));

	StaticMeshBuilding->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	DestructibleMeshBuilding->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

EGameCharacterType::Type ATowers::GetType()
{
	return EGameCharacterType::Type::TOWER;
}
