// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsComponent.h"



TArray<FVector> UPhysicsComponent::GenerateTrajectory(FVector StartPos, FVector Velocity, float MaxTime, float TimeStep, float MinZValue /*= 0*/)
{
	TArray<FVector> trajectory;
	FVector gravityVector(0, 0, Gravity);

	for (float time = 0; time < MaxTime; time += TimeStep)
	{
		FVector position = StartPos + Velocity * time + gravityVector * time * time / 2;
		if (position.Z <= MinZValue)
		{
			break;
		}
		trajectory.Add(position);
	}
	return trajectory;
}
