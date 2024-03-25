/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Flower.CPP

*/

#include "Flower.h" // Interface of Flower class

// CONSTRUCTOR
// Creates a flower, sets name, and initializes other values to 0, prints message notifying user of planted flower
Flower::Flower(string enteredName)
: Plant(enteredName), blooms{0} {
    cout << "a flower called " << Plant::getPlantName() << "!\n";
} // end Flower() constructor

// Using base class function, prints plant stats, then prints blooms
void Flower::printStage() {
    Plant::printStage();
    cout << setw(22) << "Number of Blooms = " << blooms << "\n";
} // end printStage()

// Using base class function, prints plant care options, then prints Cut Blooms
void Flower::printCareOptions(int plantNumber) {
    Plant::printCareOptions(plantNumber);
    cout << "    4 - Cut Blooms\n";
} // end printCareOptions()

// Using base class function, calls printCareOptions(), gets user's choice of action and calls that action
int Flower::careFor(int plantNumber) {
    printCareOptions(plantNumber);
    int chosenAction = Plant::careFor(plantNumber); // call base class function

    // Loop if user chooses to take multiple actions
    while (chosenAction != 0) {

        // Additional option for flower-specific cut blooms
        switch (chosenAction) {
            case(4):
                cutBlooms();
                break;
            default:
                break;
        }
        chosenAction = Plant::careFor(plantNumber);
    }
    return 0; // unused return value
} // end careFor()

// Adds height and blooms if conditions are ideal for flower
// No base class implementation
void Flower::grow() {
    srand((int)time(0));
    
    // Check for ideal flower conditions
    if (getWeedCount() < 2 && getFertilizerLevel() > 0 && getFertilizerLevel() < 4 && getWaterLevel() > 1 && getWaterLevel() < 5) {
        addHeight(1);
        // If plant is tall enough, sometimes (randomly) add flower
        if (getHeight() > 2 && rand() % 3 == 0) {
            addBloom();
        }
    }
    passTime();
} // end grow()

// Adds 1 to number of blooms
void Flower::addBloom() {
    blooms = blooms + 1;
} // end addBloom()

// Removes all blooms, prints message notifying user
void Flower::cutBlooms() {
    cout << "   * Cut " << blooms << " blooms!";
    blooms = 0;
    cout << " Blooms = " << blooms << " *\n";
} // end cutBlooms()
