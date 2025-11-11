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
const int SIMULATIONS = 20;

// Function prototypes
void displayArray(deque<Car> lanes[NUMBER_OF_LANES]);

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Create an array of deque containing Car objects
    deque<Car> lanes[NUMBER_OF_LANES];

    // Populate the array with 4 Car deque (2 Car objects each)
    for (int i = 0; i < NUMBER_OF_LANES; i++)
    {
        // Add the deque into the array
        lanes[i] = deque<Car>(INITIAL_DEQUE_SIZE);
    }

    // Display the initial deque
    cout << "Initial queue: " << endl;
    displayArray(lanes);

    // Create a loop and run 20 times
    for (int i = 0; i < SIMULATIONS; i++)
    {
        // Simulate the events
    }

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
        // Display the lane number
        cout << "Lane " << i + 1 << ":" << endl;

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
