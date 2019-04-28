// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<UBoxComponent>("TowerRoot");
	RootComponent = root;

	towerMesh = CreateDefaultSubobject<UStaticMeshComponent>("TowerMesh");
	towerMesh->AttachTo(RootComponent);

	root->OnComponentBeginOverlap.AddDynamic(this, &ATower::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
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
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Destroys the tower if hit with projectile
void ATower::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr ) )
	{
		//Update the number of towers standing in the GameMode
		FVector location = GetActorLocation();
		if (location.Y == -1300) //left tower
		{
			gm->towers[0] = 0;
		}
		else if (location.Y == 0) //middle tower
		{
			gm->towers[1] = 0;
		}
		else //right tower
		{
			gm->towers[2] = 0;
		}

		Destroy(); //remove tower from world
	}
}

