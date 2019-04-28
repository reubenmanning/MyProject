// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileSpawner.h"

// Sets default values
AProjectileSpawner::AProjectileSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<UBoxComponent>("SpawnerRoot");
	RootComponent = root;

	//y locations of the towers, so the projectiles can hit them
	spawnY[0] = -1300;
	spawnY[1] = 0;
	spawnY[2] = 1300;

	//Set the timer of the spawns to be 2 seconds
	t1 = 5.0f;

}

// Called when the game starts or when spawned
void AProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();

	//Assign the game mode to a pointer in order to access it
	UWorld* const world = GetWorld();
	if (world)
	{
		if (AMyProjectGameModeBase* myGm = Cast<AMyProjectGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			gm =myGm;
			//UE_LOG(LogTemp, Warning, TEXT("Game mode is valid!"));
		}
	}
	
}

// Called every frame
void AProjectileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Spawn a projectile every 2 seconds
	if (t1 >= 0)
	{
		t1-=DeltaTime;
	}
	if (t1 <= 0)
	{
		Spawn();
		t1 = 2.0f;
	}
}

//Spawns a projectile into the world
void AProjectileSpawner::Spawn()
{
	FRotator rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	//All towers are still standing
	if (gm->towers[0]==1 && gm->towers[1]==1 && gm->towers[2]==1)
	{
		int r = rand() % 3;
		FVector location(-4000, spawnY[r], 700);

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
		//gm->currentQuestion = p.question;
	}
	else if (gm->towers[0]==0 && gm->towers[1]==1 && gm->towers[2]==1) //Left is destoryed
	{
		int r = rand() % 2;
		FVector location(-4000, spawnY[1+r], 700);

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
		
	}
	else if (gm->towers[0]==1 && gm->towers[1]==0 && gm->towers[2]==1) //Middle is destroyed
	{
		int r = rand() % 2;
		FVector location(-4000,0,700);
		if (r==0)
		{
			location.Y = spawnY[r];
		}
		else
		{
			location.Y = spawnY[2];
		}

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
	}
	else if (gm->towers[0]==1 && gm->towers[1]==1 && gm->towers[2]==0) //Right is destroyed
	{
		int r = rand() % 2;
		FVector location(-4000, spawnY[r], 700);

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
	}
	else if (gm->towers[0]==0 && gm->towers[1]==0 && gm->towers[2]==1) //Left and middle is destroyed
	{
		FVector location(-4000, spawnY[2], 700);

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
	}
	else if (gm->towers[0]==0 && gm->towers[1]==1 && gm->towers[2]==0) //Left and right is destroyed
	{
		FVector location(-4000, spawnY[1], 700);

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
	}
	else if (gm->towers[0]==1 && gm->towers[1]==0 && gm->towers[2]==0) //Middle and right is destroyed
	{
		FVector location(-4000, spawnY[0], 700);

		GetWorld()->SpawnActor<ABanana>(projectile, location, rotation, SpawnInfo);
	}
	else //All towers have been destroyed
	{
		Destroy(); //get rid of the spawner
	}
	
	
	
}

