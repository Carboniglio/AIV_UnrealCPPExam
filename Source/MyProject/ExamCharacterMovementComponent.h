// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ExamCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UExamCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	

public:


	void MoveForward(float AxisValue,ACharacter* character);
	void MoveRight(float AxisValue, ACharacter* character);
	void Jump(ACharacter* character);
};
