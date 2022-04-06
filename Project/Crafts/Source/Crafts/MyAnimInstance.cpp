// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFrameWork/Character.h"
#include "GameFrameWork/PawnMovementComponent.h"
#include "GameFrameWork/CharacterMovementComponent.h"

void UMyAnimInstance::NativeUpdateAnimation(float _DeltaSeconds)
{
	Super::NativeUpdateAnimation(_DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	if (IsValid(Pawn))
	{

		Speed = Pawn->GetVelocity().Size();
		MovementDirection = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());

		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();
			
			if (Character->GetCharacterMovement()->GetCurrentAcceleration().Size())
				IsAccelerating = true;
			else
				IsAccelerating = false;

		}
	}
}
