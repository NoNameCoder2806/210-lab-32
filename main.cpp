// COMSC-210 | Lab 32 | Dat Hoang Vien
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

// Function prototypes
void displayDeque(const deque<Car> &tollBooth);

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Create a deque containing Car objects
    deque<Car> tollBooth(INITIAL_DEQUE_SIZE);

    // Display the initial deque
    cout << "Initial queue: " << endl;
    displayDeque(tollBooth);

    // Create an int to count the number of simulations
    int count = 0;

    // Create a loop to run the simulation
    while (tollBooth.size() != 0)
    {
        // 
    }

    return 0;
}

// Function implementations
/*
    function_name()
    What the function does
    Arguments: 
        - argument 1: what it does
        - argument 2: what it does
    Return:
        - what the function returns
*/
void displayDeque(deque<Car> &tollBooth)
{
    // Check whether the deque is empty
    if (tollBooth.empty() == 0)
    {
        // Display a message
        cout << "Empty" << endl;
    }

    // Iterate through the deque
    for (int i = 0; i < tollBooth.size(); i++)
    {
        // Display a tab in front to mâtch the sample output
        cout << "\t";

        // Use the print() member function to display the Car object
        tollBooth.at(i).print();
    }
}
