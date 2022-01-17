// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFrameWork/Character.h"
#include "GameFrameWork/PawnMovementComponent.h"


void UMyAnimInstance::NativeUpdateAnimation(float Deltaseconds)
{
	Super::NativeUpdateAnimation(Deltaseconds);

	auto pawn = TryGetPawnOwner(); 

	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size(); 
	}

	auto Character = Cast<ACharacter>(pawn);
	if (Character)
	{
		isFalling = Character->GetMovementComponent()->IsFalling();
	}

}
