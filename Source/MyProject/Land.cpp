// Fill out your copyright notice in the Description page of Project Settings.

#include "Land.h"

// Sets default values
ALand::ALand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<UBoxComponent>("LandRoot");
	RootComponent = root;

	landMesh = CreateDefaultSubobject<UStaticMeshComponent>("LandMesh");
	landMesh->AttachTo(root);

}

// Called when the game starts or when spawned
void ALand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

