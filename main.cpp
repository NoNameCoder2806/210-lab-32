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
const int SIMULATIONS = 20;
const int MIN_CHANCE = 1;
const int TOTAL_CHANCE = 100;
const int NUMBER_OF_LANES = 4;

// Function prototypes
void displayArray(deque<Car> lanes[NUMBER_OF_LANES]);
void carJoins(deque<Car> &lane);
void carLeaves(deque<Car> &lane);
void shiftLane(deque<Car> lanes[NUMBER_OF_LANES], int lane);

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
        // Display the Time
        cout << "Time: " << i + 1 << endl;

        // Iterate through each lane (deque) in the array
        for (int j = 0; j < NUMBER_OF_LANES; j++)
        {
            // Display the lane number
            cout << "Lane: " << j + 1 << " ";

            // Generate a random chance
            int chance = rand() % TOTAL_CHANCE + 1;

            // Simulate the events
            if (chance <= 50)          // 50% chance the head Car pays and leaves
            {
                // Call the carLeaves() function
                carLeaves(lanes[j]);
            }
            else                       // 50% chance a Car joins the queue
            {
                // Call the carJoins() function
                carJoins(lanes[j]);
            }
        }

        // Display all the deque (lanes) after each simulation
        displayArray(lanes);

        // Enter a new line
        cout << endl;
    }

    return 0;
}

// Function implementations
/*
    displayArray()
    Display the whole array of deque containing Car objects
    Arguments:
        - lanes: the array of deque containing all the Car objects (passed by const)
    Return: none
*/
void displayArray(deque<Car> lanes[NUMBER_OF_LANES])
{
    // Iterate through the array
    for (int i = 0; i < NUMBER_OF_LANES; i++)
    {
        // Display the lane number
        cout << "Lane " << i + 1 << " Queue: ";

        // Check whether the lane is empty or not
        if (lanes[i].empty())
        {
            // Display a message
            cout << "empty" << endl;

            // Skip to the next lane
            continue;
        }

        // Enter a new line to display the queue
        cout << endl;

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

void carJoins(deque<Car> &lane)
{
    // Create a temporary Car object
    Car temp;

    // Display a message
    cout << "Joined: ";
    
    // Display the Car object using the print() function
    temp.print();

    // Add the Car to the back of the deque
    lane.push_back(temp);
}

void carLeaves(deque<Car> &lane)
{
    // Check whether the deque is empty or not
    if (lane.empty())
    {
        // Enter a new line for formatting
        cout << endl;

        // Ignore the lane and exit the function
        return;    
    }

    // Display a message
    cout << "Paid: ";
    
    // Display the Car object using the print() function
    lane.front().print();

    // Remove the Car in the front of the deque
    lane.pop_front();
}

void shiftLane(deque<Car> lanes[NUMBER_OF_LANES], int lane)
{
    // Create an int to store the new lane index
    int newLane = lane;
    
    // Generate until we get a new lane
    while (newLane == lane)
    {
        // Generate a new lane index
        newLane = rand() % NUMBER_OF_LANES;
    }

    // Create a temporary Car object to store the rear Car to switch
    Car temp = lanes[lane].back();

    // Remove the rear Car from the original lane
    lanes[lane].pop_back();

    // Add the rear Car to the new lane
    lanes[newLane].push_back(temp);
}