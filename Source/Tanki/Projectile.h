// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Particles/ParticleSystemComponent.h>
#include <../Plugins/FX/Niagara/Source/Niagara/Classes/NiagaraSystem.h>
#include "Projectile.generated.h"

UCLASS()
class TANKI_API AProjectile : public AActor
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaTime) override;
	virtual void Explode() {};
	UFUNCTION()
		void OnMeshOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor*
			OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
			bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		class USphereComponent* SphereCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speed")
		float MoveSpeed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speed")
		float MoveRate = 0.005f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float Damage = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
		class UNiagaraSystem* TakeDamageEffect;

	FTimerHandle MoveTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float PushForce = 1000;
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	class ACannon* Cannon;
	class ATankPawn* TankPawn;
	class AActor* Owner;
	UPROPERTY()
		APawn* PlayerPawn;

	virtual void Start();

protected:
	virtual void BeginPlay() override;

	virtual void Move();

};
