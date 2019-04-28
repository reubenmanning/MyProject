// Fill out your copyright notice in the Description page of Project Settings.

#include "Banana.h"
#include "MyProjectGameModeBase.h"

// Sets default values
ABanana::ABanana()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<UBoxComponent>("BananaRoot");
	RootComponent = root;

	bananaMesh = CreateDefaultSubobject<UStaticMeshComponent>("BananaMesh");
	bananaMesh->AttachTo(RootComponent);

	bSpeed = 1.0f;

	float x = rand() % 180;
	float y = rand() % 180;
	float z = rand() % 180;
	rotationRate = FRotator(x,y,z);

}

// Called when the game starts or when spawned
void ABanana::BeginPlay()
{
	Super::BeginPlay();

	//Assign the game mode to a pointer in order to access it
	UWorld* const world = GetWorld();
	if (world)
	{
		gm = (AMyProjectGameModeBase*)world->GetAuthGameMode();
		// if (AMyProjectGameModeBase* mybGm = Cast<AMyProjectGameModeBase>(GetWorld()->GetAuthGameMode()))
		// {
		// 	gm =mybGm;
		// 	//UE_LOG(LogTemp, Warning, TEXT("Game mode is valid!"));
		// }
	}
	if (gm->mode == 0) //addition
	{
		q = new Questions('+');
	}
	else if (gm->mode == 1) //subtraction
	{
		q = new Questions('-');
	}
	else if (gm->mode == 2) //multiplication
	{
		q = new Questions('*');
	}
	else if (gm->mode == 3) //division
	{
	q = new Questions('/');
	}
	else //ultimate
	{
		q = new Questions();
	}

	answer = q->getAnswer();
	FString space = " ";
	question = FString::FromInt(q->getX()) + space + q->getSymbol() + space + FString::FromInt(q->getY());
	delete q;

	gm->list.Add(this);
	
}

// Called every frame
void ABanana::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Spin the banana
	AddActorLocalRotation(rotationRate * DeltaTime);

	//Move the banana forwards
	FVector location = GetActorLocation();
	location.X += bSpeed * DeltaTime;
	SetActorLocation(location);

	//For testing purposes. Make sure projectile does not exist forever
	if (location.X >= 1130)
	{
		//delete q; //deallocate memory where question object was placed
		Destroy();

		//Developer probably needs to update the current banana and question in the game mode
	}

}
