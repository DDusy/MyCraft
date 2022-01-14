// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"


UCLASS()
class MYCRAFT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*void UpDown(float _value);
	void LeftRight(float _value);*/

private:
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* pMesh;

	UPROPERTY(VisibleAnywhere)	// 간단한 이동 제어
	class UFloatingPawnMovement* pMoveMent;



};
