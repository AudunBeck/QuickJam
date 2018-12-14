// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Engine/GameEngine.h"
#include "Components/InputComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPawn::MoveForward(float AxisValue)
{
	AddMovementInput(FVector(1, 0.f, 0.f),AxisValue);
	//CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * speed;
}

void AMyPawn::MoveRight(float AxisValue)
{
	AddMovementInput(FVector(0.f, 1, 0.f), AxisValue);
	//CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * speed;
}

void AMyPawn::Hit()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hitting a target."));
	//UE_LOG(LogTemp, Log, TEXT("Hitting a target"));
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}
	}

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Move_X", this, &AMyPawn::MoveForward);
	InputComponent->BindAxis("Move_Y", this, &AMyPawn::MoveRight);
	
	InputComponent->BindAction("Hit", IE_Pressed, this, &AMyPawn::Hit);

}

