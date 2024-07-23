// Fill out your copyright notice in the Description page of Project Settings.


#include "ExamCharacterMovementComponent.h"
#include "GameFramework/Character.h"


void UExamCharacterMovementComponent::MoveForward(float AxisValue, ACharacter* character)
{
		//Using The AddMovement Input otherwise the ABP would not work 
	character->AddMovementInput(character->GetActorForwardVector() * AxisValue);
	
	//old method rquired to manually seet the  velocity 
	//all the checks for collisions and gravity are missing because i found  AddMovementInput which is way faster
	//Velocity.X += AxisValue * 500;
}

void UExamCharacterMovementComponent::MoveRight(float AxisValue, ACharacter* character)
{
	//Using The AddMovement Input otherwise the ABP would not work 
	character->AddMovementInput(character->GetActorRightVector() * AxisValue);

	//all the checks for collisions and gravity are missing because i found  AddMovementInput which is way faster
	//Velocity.X += AxisValue * 500;
}

void UExamCharacterMovementComponent::Jump(ACharacter* character)
{
	//calling  the Jump function of the character
	character->Jump();
}
