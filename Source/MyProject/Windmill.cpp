// Fill out your copyright notice in the Description page of Project Settings.

#include "Windmill.h"

// Sets default values
AWindmill::AWindmill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWindmill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWindmill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

