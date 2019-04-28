// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYPROJECT_API Questions
{
public:
	Questions();
	Questions(char mode);
	~Questions();
	int getX();
	int getY();
	char getSymbol();
	int getAnswer();

private:
	int x;
	int y;
	char c;
	int answer;
};
