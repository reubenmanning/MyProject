// Fill out your copyright notice in the Description page of Project Settings.

#include "Shield.h"

// Sets default values
AShield::AShield()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<UBoxComponent>("ShieldRoot");
	RootComponent = root;

	shieldMesh = CreateDefaultSubobject<UStaticMeshComponent>("ShieldMesh");
	shieldMesh->AttachTo(RootComponent);

	materialGreen = CreateDefaultSubobject<UMaterial>("greenShield");
	materialOrange = CreateDefaultSubobject<UMaterial>("orangeShield");
	materialRed = CreateDefaultSubobject<UMaterial>("redShield");

	root->OnComponentBeginOverlap.AddDynamic(this, &AShield::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AShield::BeginPlay()
{
	Super::BeginPlay();

	health = 3;
	shieldMesh->SetMaterial(0, materialGreen);

	UWorld* const world = GetWorld();
	if (world)
	{
		gm = (AMyProjectGameModeBase*)world->GetAuthGameMode();
	}
	
}

// Called every frame
void AShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Called everytime a projectile hits the shield
void AShield::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* 
OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
const FHitResult& SweepResult)
{	
	if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr ) )
	{
		health--;
		if (health == 2)
		{
			OtherActor->Destroy();
			shieldMesh->SetMaterial(0, materialOrange);
		}
		else if (health == 1)
		{
			OtherActor->Destroy();
			shieldMesh->SetMaterial(0,materialRed);
		}
		else
		{
			OtherActor->Destroy();
			Destroy();
		}

	}

	gm->list.RemoveAt(0);
}

