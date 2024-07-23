// simple  moving platform that moves on one of the axis
// Everything is Customizable in the editor  :
//The maximum distance to travel 
//the speed 
//andd the axis to move 


#include "ExamMovingPlatform.h"

AExamMovingPlatform::AExamMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}
void AExamMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartingPosition = GetActorLocation();
	

	switch (AxisToMove) {
	case(Direction::X):
		MaximumDistance += StartingPosition.X;
			break;
	case(Direction::Y):
		MaximumDistance += StartingPosition.Y;
		break;

	case(Direction::Z):
		MaximumDistance += StartingPosition.Z;
		break;
	}
}

// Called every frame
void AExamMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector NewLocation = GetActorLocation();



	switch (AxisToMove) {
	case(Direction::X):

		NewLocation.X += MovingVelocity;
		SetActorLocation(NewLocation);

		if (GetActorLocation().X > MaximumDistance || GetActorLocation().X < StartingPosition.X)
		{
			MovingVelocity *= -1;
		}

			break;
			
	case(Direction::Y):

		NewLocation.Y += MovingVelocity;
		SetActorLocation(NewLocation);

		if (GetActorLocation().Y > MaximumDistance || GetActorLocation().Y < StartingPosition.Y)
		{
			MovingVelocity *= -1;
		}


		break;
	case(Direction::Z):

		NewLocation.Z += MovingVelocity;
		SetActorLocation(NewLocation);

		if (GetActorLocation().Z > MaximumDistance || GetActorLocation().Z< StartingPosition.Z)
		{
			MovingVelocity *= -1;
		}

		break;
	}
}

