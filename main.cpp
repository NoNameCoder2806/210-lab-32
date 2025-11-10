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
const int MIN_CHANCE = 1;
const int TOTAL_CHANCE = 100;

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
    while (!tollBooth.empty())          // While the deque is not empty
    {
        // Generate a random chance from 1 to 100
        int chance = rand() % TOTAL_CHANCE + MIN_CHANCE;

        // If 1 <= chance <= 45, the Car object in the head pay its toll
        if (chance <= HEAD_PAYS_TOLL)
        {
            // Display a message
            cout << "Time: " << count++ << " ";          // Display the Time
            cout << "Operation: Car paid: ";             // Display the Operation
            tollBooth.at(0).print();                     // Calls print() to display the Car object

            // Call pop_front() to remove the Car object in the head
            tollBooth.pop_front();
        }
        else          // Otherwise, a Car object joins the line
        {
            // Create a temporary Car object
            Car temp;

            // Display a message
            cout << "Time: " << count++ << " ";          // Display the Time
            cout << "Operation: Joined lane: ";          // Display the Operation
            temp.print();                                // Calls print() to display the Car object

            // Call push_back() to add the Car object to the deque
            tollBooth.push_back(temp);
        }
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
        // Display a tab in front to mâtch the sample output
        cout << "\t";

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
