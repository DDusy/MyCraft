// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFrameWork/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	 
	pMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	pMoveMent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));

	RootComponent = pMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("Static Mesh"));

	if (SM.Succeeded())
	{
		pMesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//함수 포인터 처럼
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);

}

void AMyPawn::UpDown(float _value)
{
	AddMovementInput(GetActorForwardVector(), _value);
}

void AMyPawn::LeftRight(float _value)
{
	AddMovementInput(GetActorRightVector(), _value);
}

