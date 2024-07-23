// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExamMovingPlatform.generated.h"

UENUM(BlueprintType)
enum class Direction : uint8 {
	X = 0 UMETA(DisplayName = "X"),
	Y = 1  UMETA(DisplayName = "Y"),
	Z = 2     UMETA(DisplayName = "Z"),

};

UCLASS()
class MYPROJECT_API AExamMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExamMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere)
	float MovingVelocity;
	UPROPERTY(EditAnywhere)
	float MaximumDistance;
	
	UPROPERTY(EditAnywhere)
	Direction AxisToMove;

private:
	FVector StartingPosition;
	UStaticMeshComponent* Mesh;



};