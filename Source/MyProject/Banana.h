// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Questions.h"
//#include "MyProjectGameModeBase.h"
#include "Banana.generated.h"

//forward declaration
class AMyProjectGameModeBase;

UCLASS()
class MYPROJECT_API ABanana : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABanana();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* bananaMesh;

	UPROPERTY(EditAnywhere)
	float bSpeed; //speed of the banana

	UPROPERTY(EditAnywhere)
	FRotator rotationRate; //rate of the rotation

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString question; //string of the question

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int answer;

	Questions* q;

	AMyProjectGameModeBase* gm;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
