// Fill out your copyright notice in the Description page of Project Settings.

#include "Questions.h"

/**Constructor of a Question with undefined mode*/
Questions::Questions()
{
    char symb[4] = {'+','-','/','*'};
    int r = rand() % 4;

    c = symb[r];

    if (r < 2) //addition or subtraction is chosen
    {
        x = rand() % 101; //random number between 0 and 100
        y = rand() % 101; //random number between 0 and 100
        if (y > x) //to avoid negative answers when subracting, swap their values around
        {
            x = y - x;
            y = y - x;
            x = x + y;
        }
    }
    else if (r == 3) //multiplication is chosen
    {
        //limit numbers up to the 12 times table

        x = rand() % 13;
        y = rand() % 13;
    }
    else //division is chosen
    {
        int temp = rand() % 13;
        int temp2 = rand() % 13;
        x = temp * temp2;

        int temp3 = rand() % 2;
        if (temp3 == 0) //choose the denominator
        {
            if (temp != 0) //make sure denominator is not equal to zero
            {
                y = temp;
            }
            else
            {
                temp += 1;
                y = temp;
            }
        }
        else
        {
            if (temp2 != 0)
            {
                y = temp2;
            }
            else
            {
                temp2 += 1;
                y = temp2;
            }
        }
    }

    //Solve the answer
    switch (c)
    {
        case '+':
            answer = x + y;
            break;
        case '-':
            answer = x - y;
            break;
        case '*':
            answer = x * y;
            break;
        case '/':
            answer = x / y;
            break;
    }
}

/**Constructor of Question which takes in a char value
 * where:
 * '+' = addition,
 * '-' = subtraction,
 * '*' = multiplication,
 * '/' = division
*/
Questions::Questions(char mode)
{
    c = mode;

    if (mode == '+' || mode == '-') //addition or subtraction is chosen
    {
        x = rand() % 101; //random number between 0 and 100
        y = rand() % 101; //random number between 0 and 100
        if (y > x && mode == '-') //to avoid negative answers when subracting, swap their values around
        {
            x = y - x;
            y = y - x;
            x = x + y;
        }
    }
    else if (mode == '*') //multiplication is chosen
    {
        //limit numbers up to the 12 times table, including zero

        x = rand() % 13;
        y = rand() % 13;
    }
    else //division is chosen
    {
        int temp = rand() % 13;
        int temp2 = rand() % 13;
        x = temp * temp2;

        int temp3 = rand() % 2;
        if (temp3 == 0) //choose the denominator
        {
            if (temp != 0) //make sure denominator is not equal to zero
            {
                y = temp;
            }
            else
            {
                temp += 1;
                y = temp;
            }
        }
        else
        {
            if (temp2 != 0)
            {
                y = temp2;
            }
            else
            {
                temp2 += 1;
                y = temp2;
            }
        }
    }

    //Solve the answer
    switch (mode)
    {
        case '+':
            answer = x + y;
            break;
        case '-':
            answer = x - y;
            break;
        case '*':
            answer = x * y;
            break;
        case '/':
            answer = x / y;
            break;
    }
}

/**Destructor of Question*/
Questions::~Questions()
{
}

/**returns the first number of a Question*/
int Questions::getX()
{
    return x;
}

/**returns the second number of a Question*/
int Questions::getY()
{
    return y;
}

/**returns the maths symbol used for the Question*/
char Questions::getSymbol()
{
    return c;
}

/**returns the answer of the Question*/
int Questions::getAnswer()
{
    return answer;
}