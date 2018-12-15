// Fill out your copyright notice in the Description page of Project Settings.

#include "chain.h"
#include "Engine.h"

// Sets default values
Achain::Achain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Achain::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void Achain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector player1Loc;
	FVector player2Loc;
	FVector tempLocation;

	if (!done)
	{
		players.Add(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		players.Add(UGameplayStatics::GetPlayerController(GetWorld(), 1));
		done = true;
	}
	if (players[0])
	{
		if (GEngine)
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TEXT("PlayerOneFound"));
		player1Loc = players[0]->GetCharacter()->GetActorLocation();
	}
	else
	{
		player1Loc = { 0.f, 0.f, 0.f };
	}
		
	if(players[1])
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TEXT("PlayerTwoFound"));
		player2Loc = players[1]->GetCharacter()->GetActorLocation();
	}
	else
	{
		player2Loc = { 0.f, 0.f, 0.f };
	}

	p1Distance = sqrtf(powf((player1Loc.X - tempLocation.X), 2) + powf((player1Loc.Y - tempLocation.Y), 2));
	p2Distance = sqrtf(powf((player2Loc.X - tempLocation.X), 2) + powf((player2Loc.Y - tempLocation.Y), 2));

	//if (p1Distance > maxDistance)
	//{
	//	FVector ballDirection = tempLocation - player1Loc;
	//	players[0]->GetCharacter()->AddMovementInput(ballDirection, dragForce);
	//}

	//if (p2Distance > maxDistance)
	//{
	//	FVector ballDirection = tempLocation - player2Loc;
	//	players[1]->GetCharacter()->AddMovementInput(ballDirection, dragForce);
	//}
}
