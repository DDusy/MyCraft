// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::NativeUpdateAnimation(float Deltaseconds)
{
	Super::NativeUpdateAnimation(Deltaseconds);

	auto pawn = TryGetPawnOwner(); 

	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size(); 
	}
}
