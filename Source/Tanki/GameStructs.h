// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStructs.generated.h"

UENUM(BlueprintType)
enum class ECannonType : uint8
{
	FireProjectile = 0 UMETA(DisplayName = "Use Projectile"),
	FireTrace = 1 UMETA(DisplayName = "Use trace"),
	FireProjectile2 = 2 UMETA(DisplayName = "Use Projectile2"),
};

USTRUCT()
struct FDamageData
{
	GENERATED_BODY()
	
	UPROPERTY()
		float DamageValue;
	UPROPERTY()
		AActor* Instigator;
	UPROPERTY()
		AActor* DamageMaker;
};

USTRUCT()
struct FSaveData
{
	GENERATED_BODY()

	UPROPERTY()
	uint32 ID;
	UPROPERTY()
	float CurrentHP;
	UPROPERTY()
	int CurrentPatrons;
};


UCLASS()
class TANKI_API UGameStructs : public UObject
{
	GENERATED_BODY()
	
};
