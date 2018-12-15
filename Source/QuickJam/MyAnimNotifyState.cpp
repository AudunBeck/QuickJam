// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAnimNotifyState.h"
#include "MyCharacter.h"
#include "Sword.h"
#include "Components/SkeletalMeshComponent.h"


void UMyAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase * Animation, float TotalDuration)
{
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		TArray<AActor*> components;
		AMyCharacter * character = Cast<AMyCharacter>(MeshComp->GetOwner());

		if (character != NULL)
		{
			character->GetAttachedActors(components);
			if (components[0] != NULL)
			{
				ASword *wp = Cast<ASword>(components[0]);
				if (wp != NULL)
					wp->StartAttack();
				//Look for weapon component
				//If found do the code for it looking to hit something.
			}
			

		}
	}
}

void UMyAnimNotifyState::NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation)
{
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		TArray<AActor*> components;
		AMyCharacter * character = Cast<AMyCharacter>(MeshComp->GetOwner());

		if (character != NULL)
		{
			character->GetAttachedActors(components);
			if (components[0] != NULL)
			{
				ASword *wp = Cast<ASword>(components[0]);
				if (wp != NULL)
					wp->EndAttack();
				//Look for weapon component
				//If found do the code for it looking to hit something.
				character->Attacking = false;
			}


		}
	}
}
