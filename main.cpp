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
const int HEAD_PAYS_TOLL = 46;
const int CAR_JOINS_QUEUE = 39;
const int REAR_SHIFTS_LANE = 15;
const int CAR_JOINS_EMPTY_LANE = 50;

// Function prototypes
void displayArray(deque<Car> lanes[NUMBER_OF_LANES]);
void carJoins(deque<Car> &lane);
void carLeaves(deque<Car> &lane);
void shiftLane(deque<Car> lanes[NUMBER_OF_LANES], int lane);
void emptyLane(deque<Car> &lane);

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

            // Check whether the deque (lane) is empty or not
            if (lanes[j].empty())
            {
                // If the lane is empty, the probabilities will be just 50/50 if a new Car enters or not
                // Call the emptyLane() function to simulate this special situation
                emptyLane(lanes[j]);

                // Skip to the next deque in the array
                continue;
            }
            else
            {
                // Otherwise if the lane is not empty, we simulate normally
                // Generate a random chance
                int chance = rand() % TOTAL_CHANCE + 1;

                // Check the chances to simulate the events
                if (chance <= HEAD_PAYS_TOLL)                                 // The first 46%     
                {
                    // Call the carLeaves() function and pass the lane in
                    carLeaves(lanes[j]);
                }
                else if (chance <= HEAD_PAYS_TOLL + CAR_JOINS_QUEUE)          // The next 39%
                {
                    // Call the carJoins() function and pass the lane in
                    carJoins(lanes[j]);
                }
                else                                                          // The last 15%
                {
                    // Call the shiftLane() function, pass in the array and the lane's index
                    shiftLane(lanes, j);
                }
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

/*
    carJoins()
    A Car joins the lane at the back
    Arguments:
        - lane: the deque representing the lane in simulation (passed by reference)
    Return: none
*/
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

/*
    carLeaves()
    The Car at the front pays its toll and leaves the queue
    Arguments:
        - lane: the deque representing the lane in simulation (passed by reference)
    Return: none
*/
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

/*
    shiftLane()
    The Car shifts from the original lane to another one randomly
    Arguments:
        - lanes: the array of deque containing all the Car objects
        - lane: the index of the original lane
    Return: none
*/
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

    // Display a message
    cout << "Switched: ";

    // Call the print() member function to display the Car's information
    temp.print();

    // Add the rear Car to the new lane
    lanes[newLane].push_back(temp);
}

/*
    emptyLane()
    Simulate the empty lanes
    Arguments:
        - lane: the deque representing the lane in simulation (passed by reference)
    Return: none
*/
void emptyLane(deque<Car> &lane)
{
    // If the lane is empty, the chance for a Car to join will only be 50/50
    // Generate a random chance
    int chance = rand() % TOTAL_CHANCE + 1;

    // Check the chance
    if (chance <= CAR_JOINS_EMPTY_LANE)          // 50% chance
    {
        // Call the carJoins() function to add a new Car to the lane
        carJoins(lane);
    }
    else                                         // The other 50% chance
    {
        // Otherwise, nothing happens
        // Exit the function
        return;
    }
}