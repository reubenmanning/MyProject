// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Land.generated.h"

UCLASS()
class MYPROJECT_API ALand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALand();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* landMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
