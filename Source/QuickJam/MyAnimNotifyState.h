// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "MyAnimNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class QUICKJAM_API UMyAnimNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase * Animation, float TotalDuration);
	void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase * Animation);
	
	
	
	
};
