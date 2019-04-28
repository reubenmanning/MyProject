// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProjectGameModeBase.h"

AMyProjectGameModeBase::AMyProjectGameModeBase()
{
    PrimaryActorTick.bStartWithTickEnabled = true;
    PrimaryActorTick.bCanEverTick = true;

    //set score to zero when starting the game
    score = 0;

    currentQuestion = "";

    //towers standing when game starts
    towers[0] = 1;
    towers[1] = 1;
    towers[2] = 1;

    lCheck = false;
    midCheck = false;
    rCheck = false;

    gameOver = false;
}

void AMyProjectGameModeBase::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyProjectGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // FString testing = "";
    // FString space = " ";
    if (list.Num() != 0)
    {
        currentQuestion = list[0]->question;
        // for (int i = 0; i < list.Num(); i++) {
        //     testing += (list[i]->question) + space;
        //     currentQuestion = testing;
        // }
    }

    //destroy projectiles (or ignore) in lane if towers no longer exist
    if (towers[0] == 0 && lCheck == false)
    {
        for (int i = 0; i < list.Num(); i++)
        {
            FVector location = list[i]->GetActorLocation();
            if (location.Y == -1300)
            {
                list.RemoveAt(i);
            }
        }
        lCheck = true;
    }
    else if (towers[1] == 0 && midCheck == false)
    {
        for (int i = 0; i < list.Num(); i++)
        {
            FVector location = list[i]->GetActorLocation();
            if (location.Y == 0)
            {
                list.RemoveAt(i);
            }
        }
        midCheck = true;
    }
    else if (towers[2] == 0 && rCheck == false)
    {
        for (int i = 0; i < list.Num(); i++)
        {
            FVector location = list[i]->GetActorLocation();
            if (location.Y == 1300)
            {
                list.RemoveAt(i);
            }
        }
        rCheck = true;
    }
    else if (towers[0]==0 && towers[1]==0 && towers[2]==0 && lCheck==true && midCheck==true && rCheck==true)
    {
        for (int i = 0; i < list.Num(); i++)
        {
            FVector location = list[i]->GetActorLocation();
            list.RemoveAt(i);
        }
        gameOver = true;
    }
    // if (list.Num() != 0 && list[0] == nullptr)
    // {
    //     currentQuestion = "remember to delete the front of the list!!!";
    // }
}

//Checks if the user input is correct
void AMyProjectGameModeBase::checkAnswer()
{

}