// COMSC-210 | Lab 33 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

// Constants
const int INITIAL_DEQUE_SIZE = 2;
const int HEAD_PAYS_TOLL = 55;
const int CAR_JOINS_LINE = 45;
const int MIN_CHANCE = 1;
const int TOTAL_CHANCE = 100;
const int NUMBER_OF_LANES = 4;

// Function prototypes
void displayArray(deque<Car> lanes[NUMBER_OF_LANES]);

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Create an array of deque containing Car objects
    deque<Car> lanes[NUMBER_OF_LANES];

    // Display the initial deque
    cout << "Initial queue: " << endl;
    displayArray(lanes);

    // Create an int to count the number of simulations
    int count = 1;

    return 0;
}

// Function implementations
/*
    displayArray()
    Display the whole array of deque containing Car objects
    Arguments:
        - lanes: the array of deque containing all the Car objects
    Return: none
*/
void displayArray(deque<Car> lanes[NUMBER_OF_LANES])
{
    // Iterate through the array
    for (int i = 0; i < NUMBER_OF_LANES; i++)
    {
        // Iterate through each deque
        for (int j = 0; j < lanes[i].size(); j++)
        {
            // Display a tab in front to mâtch the sample output
            cout << "\t";

            // Use the print() member function to display the Car object
            lanes[i].at(j).print();
        }
    }
}
