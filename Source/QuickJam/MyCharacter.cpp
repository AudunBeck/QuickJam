// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Engine/GameEngine.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 480.f, 0.f);
}

void AMyCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(FVector(1, 0.f, 0.f), AxisValue);
}

void AMyCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(FVector(0.f, 1, 0.f), AxisValue);
}

void AMyCharacter::Hit()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TEXT("Hitting a target."));
	//UE_LOG(LogTemp, Log, TEXT("Hitting a target"));
}


// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Move_X", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("Move_Y", this, &AMyCharacter::MoveRight);

	InputComponent->BindAction("Hit", IE_Pressed, this, &AMyCharacter::Hit);

}

