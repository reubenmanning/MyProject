// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Banana.h"
#include "Components/BoxComponent.h"
#include "MyProjectGameModeBase.h"
#include "ProjectileSpawner.generated.h"

UCLASS()
class MYPROJECT_API AProjectileSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileSpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* root;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABanana> projectile;

	//spawns a projectile in front of a tower
	void Spawn();

	//An array of 3 potential Y positions for the projectile spawn points
	int spawnY[3];

	//Float for keeping track of time
	float t1;

	//A pointer to the game mode of the level
	AMyProjectGameModeBase* gm;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
