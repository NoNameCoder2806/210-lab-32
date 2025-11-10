// COMSC-210 | Lab 32 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

// Constants
const int INITIAL_DEQUE_SIZE = 2;

// Function prototypes

// Main function
int main()
{
    // Create a deque containing Car objects
    deque<Car> tollBooth(INITIAL_DEQUE_SIZE);

    // Display the initial deque by iterating through the deque
    for (int i = 0; i < tollBooth.size(); i++)
    {
        // Display the Car object
        tollBooth[i].print();
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
