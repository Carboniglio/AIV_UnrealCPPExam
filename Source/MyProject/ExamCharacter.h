// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "ExamCharacterMovementComponent.h"
#include "ExamCharacter.generated.h"

UCLASS()
class MYPROJECT_API AExamCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AExamCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Moveforward(float AxisVal);
	void MoveRight(float AxisVal);
	void CustomJump();
	void RayCast();
	void AddforceToObject(FHitResult hit, FVector ForcetoApply);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UExamCharacterMovementComponent* MovementComponent;

	void SaveGame();
	void LoadGame();
};