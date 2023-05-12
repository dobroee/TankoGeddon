// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "TankPawn.h"
#include <DrawDebugHelpers.h>


ATankController::ATankController(const FObjectInitializer& Obj) : Super(Obj)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void ATankController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	TankPawn = Cast<ATankPawn>(InPawn);
}

void ATankController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAxis("MoveForward", this, &ATankController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &ATankController::MoveRight);
		InputComponent->BindAxis("RotateRight", this, &ATankController::RotateRight);
		InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATankController::Fire);
		InputComponent->BindAction("FireSpecial", EInputEvent::IE_Pressed, this, &ATankController::FireSpecial);
		InputComponent->BindAction("ChangeCannon", EInputEvent::IE_Pressed, this, &ATankController::ChangeCannon);
		InputComponent->BindKey(EKeys::LeftMouseButton, IE_Released, this, &ATankController::OnLeftMouseButtonUp);
	}
}


void ATankController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector MouseDirection;
	DeprojectMousePositionToWorld(MousePos, MouseDirection);
	if (TankPawn)
	{
		FVector tankPosition = TankPawn->GetActorLocation();
		MousePos.Z = tankPosition.Z;
		FVector dir = MousePos - tankPosition;
		dir.Normalize();
		MousePos = tankPosition + dir * 1000;
	}
	
	//DrawDebugLine(GetWorld(), tankPosition, MousePos, FColor::Green, false, 0.1f, 0, 5);
}

void ATankController::MoveForward(float Value)
{
	if (TankPawn)
	{
		TankPawn->MoveForward(Value);
	}
}
void ATankController::MoveRight(float Value)
{
	if (TankPawn)
	{
		TankPawn->MoveRight(Value);
	}
}

void ATankController::RotateRight(float Value)
{
	if (TankPawn)
	{
		TankPawn->RotateRight(Value);
	}
}

void ATankController::Fire()
{
	if (TankPawn)
	{
		TankPawn->Fire();
	}
}

void ATankController::FireSpecial()
{
	if (TankPawn)
	{
		TankPawn->FireSpecial();
	}
}

void ATankController::ChangeCannon()
{
	//ATankPawn* TankPawn = Cast<ATankPawn>(OtherActor);
	//TSubclassOf<class ACannon> CannonClass = TankPawn->CannonClass;

	if (TankPawn)
	{
		if (TankPawn->CannonNumber < 3)
		{
			TankPawn->CannonNumber++;
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Cannon number: %d"), TankPawn->CannonNumber));
		}
		else
		{
			TankPawn->CannonNumber = 1;
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Cannon number: %d"), TankPawn->CannonNumber));
		}

		if (TankPawn->CannonNumber == 1)
		{
			TankPawn->SetupCannon(TankPawn->CannonClass1);
		}
		else if (TankPawn->CannonNumber == 2)
		{
			TankPawn->SetupCannon(TankPawn->CannonClass2);
		}
		else if (TankPawn->CannonNumber == 3)
		{
			TankPawn->SetupCannon(TankPawn->CannonClass3);
		}
	}
}

void ATankController::OnLeftMouseButtonUp()
{
	if (OnMouseButtonUp.IsBound())
	{
		OnMouseButtonUp.Broadcast();
	}
}
