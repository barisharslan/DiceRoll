/*
This program lets the user choose their type of die
(or coin) and rolls it for them, useful for a D&D game

Creator: Barish Arslan
Language: C++
IDE: Code::Blocks 13.12
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>

int roll(int dice, int howMany, int additions);  // roll function accepts type of dice, how many rolls, and if there should be any additions to the rollsum
int getNumber(int lowerLimit);
bool getResponse();


int main()
{
    bool rollAgain;
    do
    {
        std::cout << "How many sides does your die have?" << std::endl;
        int sides = getNumber(2);                                               //minimum sides a die can have is 2, as in a coin
        std::cout << std::endl << "Your die has " << sides << " sides." << std::endl;
        std::cout << std::endl << "How many times do you want to roll your die?" << std::endl;
        int rolls = getNumber(1);                                               // minimum times to roll is 1 time
        std::cout << std::endl << "You will roll the die " << rolls << " time(s)." << std::endl;
        std::cout << std::endl << "What is going to be added to the sum of your rolls?" << std::endl;
        int addToSum = getNumber(-5);
        std::cout << std::endl << "You will add " << addToSum << " to your roll." << std::endl << std::endl;
        roll(sides, rolls, addToSum);
        std::cout << "Would you like to roll again? (Y/N)" << std::endl;
        rollAgain = getResponse();
        std::cout << std::endl;
    }while(rollAgain == true);
    std::cout << "Thanks for playing!";

}

int roll(int dice, int howMany, int additions)
{
    int lower = 1;
    int upper = dice;
    int sum = 0;
    int roll = 0;
    for (int i = 1; i <= howMany; i++)
    {
        roll = rand() % dice + lower;
        std::cout << "Roll " << i << ":" << std::setw(12) << std::right << roll << std::endl;
        sum +=  roll;
    }
    std::cout << "Your roll sum is " << sum << "," << std::endl << "plus your addition of " << additions;
    sum += additions;
    std::cout << " will give you a total of " << sum << std::endl;
}

int getNumber(int lowerLimit)
{
    double number = 0.0;
    while(!(std::cin >> number && number >= lowerLimit && number == static_cast<int>(number))) //checks if cin returns a whole number answer above 1
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: " << std::endl;
    }
    return number;
}

bool getResponse()
{
    bool repeat;
    bool error = true;
    std::string response;
    while(error = true)
    {

        std::cin >> response;


        if (response == "Y" || response == "y")
        {
            repeat = true;
            error = false;
            break;
        }
        else if (response == "N" || response == "n")
        {
            repeat = false;
            error = false;
            break;
        }
        else
        {
            error = true;
            std::cout << "Invalid input. Try again: ";
        }
    }
    return repeat;
}
