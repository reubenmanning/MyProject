// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyProjectGameModeBase.h"
#include "Shield.generated.h"

UCLASS()
class MYPROJECT_API AShield : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShield();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* shieldMesh;

	UPROPERTY(EditAnywhere)
	UMaterial* materialGreen;

	UPROPERTY(EditAnywhere)
	UMaterial* materialOrange;

	UPROPERTY(EditAnywhere)
	UMaterial* materialRed;

	AMyProjectGameModeBase* gm;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult& SweepResult);

	int health;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
