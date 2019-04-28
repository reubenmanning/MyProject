// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Questions.h"
#include "Banana.h"
#include "MyProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	//Set default values
	AMyProjectGameModeBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int score; //Player score

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mode; //Chosen gameplay mode

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString currentQuestion; //Question to display as text on the HUD

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int userAnswer; //the last entered value from the user

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ABanana*> list;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABanana* currentBanana; //Pointer to the closest banana to the towers

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABanana* nextBanana; //Pointer to the next closest banana

	void checkAnswer();

	bool lCheck;
	bool midCheck;
	bool rCheck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool gameOver;

	//Array that shows which towers are still standing, where 1 is true and 0 is false
	int towers[3];
};