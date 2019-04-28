// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyProjectGameModeBase.h"
#include "Tower.generated.h"

UCLASS()
class MYPROJECT_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* towerMesh;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//A pointer to the game mode of the level
	AMyProjectGameModeBase* gm;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
