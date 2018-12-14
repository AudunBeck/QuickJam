// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.h"
#include "chain.generated.h"

UCLASS()
class QUICKJAM_API Achain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Achain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TArray<APlayerController*> players;

	UPROPERTY(EditAnywhere)
		int numPlayers = 0;
	bool done = false;

	UPROPERTY(EditAnywhere)
		float p1Distance;

	UPROPERTY(EditAnywhere)
		float p2Distance;

	UPROPERTY(EditAnywhere)
		float maxDistance = 1000;
	UPROPERTY(EditAnywhere)
		float dragForce = 1.5f;
	
};
