// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExamOpeningDoor.generated.h"

UCLASS()
class MYPROJECT_API AExamOpeningDoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExamOpeningDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION( BlueprintCallable)
	bool OpenDoor(bool isLeft);


	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	bool  openLeft;
	bool openRight;
	float maxOpening;
};
