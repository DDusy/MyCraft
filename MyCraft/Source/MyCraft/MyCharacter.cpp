// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
//#include "GameFrameWork/PawnMovementComponent.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "MyAnimInstance.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pSpringArms = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARMS"));
	pCamera= CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	pSpringArms->SetupAttachment(GetCapsuleComponent());
	pCamera->SetupAttachment(pSpringArms);

	pSpringArms->TargetArmLength = 400.f;
	pSpringArms->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f,0.f,-88.f),FRotator(0.f,-90.f,0.f));
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));

	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	 AnimInstance =Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	 AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
	
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
	
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed,this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);


	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);

}

void AMyCharacter::UpDown(float _value)
{
	//if (this->GetMovementComponent()->IsFalling()) return;

	AddMovementInput(GetActorForwardVector(), _value);
}

void AMyCharacter::LeftRight(float _value)
{
	AddMovementInput(GetActorRightVector(), _value);
}

void AMyCharacter::Yaw(float _value)
{
	AddControllerYawInput(_value);
}

void AMyCharacter::Attack()
{
	if(IsAttacking)
		return;

	auto Animinstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());


	Animinstance->PlayAttackMontage();
	
	IsAttacking = true;
}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool binterrupted)
{
	IsAttacking = false;
}
