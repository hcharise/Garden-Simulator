/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Shrub.CPP
 
*/

#include "Shrub.h" // Interface of Shrub class

// CONSTRUCTOR
// Creates a shrub, sets name, and initializes other values to 0, prints message notifying user of planted shrub
Shrub::Shrub(string enteredName)
: Plant(enteredName), branches{0} {
    cout << "a shrub called " << Plant::getPlantName() << "!\n";
} // end Shrub() constructor

// Using base class function, prints plant stats, then prints branches
void Shrub::printStage() {
    Plant::printStage();
    cout << setw(22) << "Number of Branches = " << branches << "\n";
} // end printStage()

// Using base class function, prints plant care optinos, then prints Prune Branches
void Shrub::printCareOptions(int plantNumber) {
    Plant::printCareOptions(plantNumber);
    cout << "    4 - Prune Branches\n";
} // end printCareOptions()

// Using base class function, calls printCareOptions(), gets user's choice of action and calls that action
int Shrub::careFor(int plantNumber) {
    printCareOptions(plantNumber);
    int chosenAction = Plant::careFor(plantNumber); // call base class function

    // Loop if user chooses to take multiple actions
    while (chosenAction != 0) {

        // Additional option for shrub-specific prune branches
        switch (chosenAction) {
            case(4):
                pruneBranches();
                break;
            default:
                break;
        }
        chosenAction = Plant::careFor(plantNumber);
    }
    return 0; // unused return value
} // end careFor()

// Add height and branches if conditions are idea for shrub
// No base class implementation
void Shrub::grow() {
    srand((int)time(0));
    
    // Check for ideal shrub conditions
    if (getWaterLevel() > 0 && getWaterLevel() < 8 && getFertilizerLevel() > -1 && getFertilizerLevel() < 6 && getWeedCount() < 4) {
        addHeight(2);
        // If plant is tall enough, sometimes (randomly) add branches
        if (getHeight() > 2 && rand() % 2 == 0) {
            addBranch();
        }
    }
    passTime();
} // end grow()

// Adds 1 to number of branches
void Shrub::addBranch() {
    branches = branches + 1;
} // end addBranch()

// Removes all branches, prints message notifying user
void Shrub::pruneBranches() {
    cout << "   * Pruned " << branches << " brances!";
    branches = 0;
    cout << " Branches = " << branches << " *\n";
} // end pruneBranches()
