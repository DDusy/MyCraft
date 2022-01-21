// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFrameWork/Character.h"
#include "GameFrameWork/PawnMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Yin_Skeleton_Montage.Yin_Skeleton_Montage'"));

	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

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

void UMyAnimInstance::PlayAttackMontage()
{
	
	Montage_Play(AttackMontage,1.f);

}
