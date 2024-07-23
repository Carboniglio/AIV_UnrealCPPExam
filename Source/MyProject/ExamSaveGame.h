
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ExamSaveGame.generated.h"


UCLASS()
class MYPROJECT_API UExamSaveGame : public USaveGame
{
	GENERATED_BODY()
	
	UExamSaveGame();
public:
	UPROPERTY(EditAnywhere)
	FVector PlayerLocation;
};
