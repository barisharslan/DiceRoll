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
#include <ctime>

void roll(int dice, int howMany, int additions);  // roll function accepts type of dice, how many rolls, and if there should be any additions to the sum of the roll
int getNumber(int lowerLimit);                    // reads user input for each question, using the parameter as a lower limit to filter out invalid inputs, returns that value
bool getResponse();                               // prompts the user whether they want to roll again or not, returns true or false


int main()
{
    bool rollAgain;
    do
    {
        srand(time( NULL ));                                                                 //seeds the RNG with the time the user launches the program (or when the loop repeats),
        std::cout << "How many sides does your die have?" << std::endl;                      //to produce the most random pseudo-random numbers  possible
        int sides = getNumber(2);                                                            //minimum sides a die can have is 2, as in a coin
        std::cout << std::endl << "Your die has " << sides << " sides." << std::endl;
        std::cout << std::endl << "How many times do you want to roll your die?" << std::endl;
        int rolls = getNumber(1);                                                            // minimum times to roll is 1 time
        std::cout << std::endl << "You will roll the die " << rolls << " time(s)." << std::endl;
        std::cout << std::endl << "What is going to be added to the sum of your rolls?" << std::endl;
        int addToSum = getNumber(-5);                                                        //lowest negative modifier in D&D is -5
        std::cout << std::endl << "You will add " << addToSum << " to your roll." << std::endl << std::endl;
        roll(sides, rolls, addToSum);                                                        //calls roll with user input data
        std::cout << "Would you like to roll again? (Y/N)" << std::endl;
        rollAgain = getResponse();
        std::cout << std::endl;
    }while(rollAgain == true);  // if user enters Y, getResponse returns true and the loop repeats, if user enters N , getResponse returns false and
    std::cout << "Thanks for playing!";
    return 0;
}

void roll(int dice, int howMany, int additions)
{
    int lower = 1;                                                                                        //lowest possible roll is 1
    int upper = dice;                                                                                     //the upper limit ie the number of sides the dice has
    int sum = 0;
    int yourRoll = 0;

    for (int i = 1; i <= howMany; i++)                                                                    //for however many rolls requested,
    {
        yourRoll = rand() % dice + lower;                                                                 //generates random number between the limit set by the dice
        std::cout << std::left << "Roll " << std::setw(3) << std::left << i << std::setw(2)
        << std::left << ":" << std::setw(12) << std::right << yourRoll << std::endl;                      // prints each roll individually
        sum +=  yourRoll;                                                                                 //adds it to the total sum
    }
    std::cout << std::endl << "Your roll sum is " << sum << "," << std::endl
    << "plus your addition of " << additions << "," << std::endl;                                         //prints your total before modifier
    sum += additions;                                                                                     //adds the modifier
    std::cout << "will give you a total of " << sum << std::endl;                                         //prints total after modifier
}

int getNumber(int lowerLimit)
{
    double number = 0.0;
    while(!(std::cin >> number && number >= lowerLimit && number == static_cast<int>(number))) //checks if cin returns a whole number answer above the lowerLimit parameter
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: " << std::endl;
    }
    return number;
}

bool getResponse()
{
    bool repeat;                   //variable returned, so if it returns true then the loop in main function repeats
    bool error = true;             //error variable to check for invalid input
    std::string response;
    while(error == true)
    {

        std::cin >> response;

        if (response == "Y" || response == "y")
        {
            repeat = true;        //main loop repeats
            error = false;        //sets error to false so while loop closes
            break;
        }
        else if (response == "N" || response == "n")
        {
            repeat = false;       //main loop doesn't repeat
            error = false;        //makes while loop close
            break;
        }
        else
        {
            error = true;         //continues while loop until valid input is received
            std::cout << "Invalid input. Try again: ";
        }
    }
    return repeat;
}
