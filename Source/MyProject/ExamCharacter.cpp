#include "ExamCharacter.h"
#include"ExamCharacterMovementComponent.h"
#include"Kismet/GameplayStatics.h"
#include"ExamSaveGame.h"

// Setting ExamMovement Component as a default character movement component of the ExamCharacter
AExamCharacter::AExamCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UExamCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
	
{

	PrimaryActorTick.bCanEverTick = true;

	//creating a pointer to the movement component, otherwise   i could not call the methods from GetCharacterMovement()
	MovementComponent =Cast<UExamCharacterMovementComponent>( GetCharacterMovement());
	
}


void AExamCharacter::BeginPlay()
{
	Super::BeginPlay();
}



void AExamCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AExamCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Binding all the inputs 
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AExamCharacter::Moveforward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AExamCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AExamCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AExamCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AExamCharacter::Jump);

	PlayerInputComponent->BindAction(TEXT("Save"), IE_Pressed, this, &AExamCharacter::SaveGame);
	PlayerInputComponent->BindAction(TEXT("Load"), IE_Pressed, this, &AExamCharacter::LoadGame);
	PlayerInputComponent->BindAction(TEXT("Cast"), IE_Repeat, this, &AExamCharacter::RayCast);




}

void AExamCharacter::SaveGame()
{
	//Creating an instance of tthe savegame class
	UExamSaveGame* SaveGameInstance = Cast<UExamSaveGame>(UGameplayStatics::CreateSaveGameObject(UExamSaveGame::StaticClass()));

	//Setting the parameters to save (in this case the player location )
	SaveGameInstance->PlayerLocation = this->GetActorLocation();

	//Saving the instance
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("ExamSlot"), 0);

	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Saved! "));
}

void AExamCharacter::LoadGame()
{
	//Creating an instance of tthe savegame class
	UExamSaveGame* SaveGameInstance = Cast<UExamSaveGame>(UGameplayStatics::CreateSaveGameObject(UExamSaveGame::StaticClass()));
	SaveGameInstance = Cast<UExamSaveGame>(UGameplayStatics::LoadGameFromSlot("ExamSlot", 0));
	this->SetActorLocation(SaveGameInstance->PlayerLocation);


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Loaded! "));

}



//All the methods Check if the pointer  is valid, then call the methods from the movement component 
void AExamCharacter::Moveforward(float AxisVal)
{

	if (MovementComponent)
	{
		MovementComponent->MoveForward(AxisVal, this);
	}

}


void AExamCharacter::MoveRight(float AxisVal)
{
	if (MovementComponent)
	{
		MovementComponent->MoveRight(AxisVal, this);
	}
}

void AExamCharacter::CustomJump()
{
	if (MovementComponent)
	{
		MovementComponent->Jump(this);
	}
}


//Simple method to shoot a RayCast
void AExamCharacter::RayCast()
{
	FVector start = GetActorLocation();
	FVector forward = GetActorForwardVector();
	start = FVector(start.X + (forward.X * 100), start.Y + (forward.Y * 100), start.Z + (forward.Z * 100));
	FVector end = start + (forward * 500);

	FHitResult hit;

	if (GetWorld())
	{
		bool actorHit = GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Pawn, FCollisionQueryParams(), FCollisionResponseParams());
		DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 2.f, 0.f, 10.f);

		if (actorHit && hit.GetActor())
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, hit.GetActor()->GetFName().ToString());
			FVector forcetoApply = end - start;
			AddforceToObject(hit, forcetoApply);
			
		}
	}

}

// method to apply force to an  object hitted by the raycast
void AExamCharacter::AddforceToObject(FHitResult hit , FVector ForcetoApply)
{
	UPrimitiveComponent* hitComponent = hit.GetComponent();
	if (hitComponent->IsSimulatingPhysics())
	{
		
		ForcetoApply.Normalize();
		ForcetoApply *= 1000000;
		hitComponent->AddForceAtLocation(ForcetoApply, hit.ImpactPoint);
	}
}
