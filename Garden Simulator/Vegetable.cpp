/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Vegetable.CPP

*/

#include "Vegetable.h" // Interface of Vegetable class

// CONSTRUCTOR
// Creates a vegetable, sets name, and initializes other valuees to 0, prints message notifying user of planted vegetable
Vegetable::Vegetable(string enteredName)
: Plant(enteredName), veggies{0} {
    cout << "a vegetable called " << Plant::getPlantName() << "!\n";
} // end Vegetable() constructor

// Using base class function, prints plant stats, then prints harvest
void Vegetable::printStage() {
    Plant::printStage();
    cout << setw(22) << "Number of Veggies = " << veggies << "\n";
} // end printStage()

// Using base calss function, prints plant care options, then prints Harvest Vegetables
void Vegetable::printCareOptions(int plantNumber) {
    Plant::printCareOptions(plantNumber);
    cout << "    4 - Harvest Veggies\n";
} // end printCareOptions()

// Using base class function, calls printCareOptions(), gets user's choice of action and calls that action
int Vegetable::careFor(int plantNumber) {
    printCareOptions(plantNumber);
    int chosenAction = Plant::careFor(plantNumber); // call base class function

    // Loop if user chooses to take multiple actions
    while (chosenAction != 0) {

        // Additional option for vegetable specific harvest veggies
        switch (chosenAction) {
            case(4):
                harvestVeggies();
                break;
            default:
                break;
        }
        chosenAction = Plant::careFor(plantNumber);
    }
    return 0; // unused return value
} // end careFor()

// Adds height and veggies if conditions are idea for vegetable
// No base class implementation
void Vegetable::grow() {
    srand((int)time(0));
    
    // Check for ideal vegetable conditions
    if (getWaterLevel() > 2 && getWaterLevel() < 6 && getFertilizerLevel() > 1 && getFertilizerLevel() < 5 && getWeedCount() < 3) {
        addHeight(2);
        // If plant is tall enough, sometimes (randomly) add veggie
        if (getHeight() > 3 && rand() % 2 == 0) {
            addVeggie();
        }
    }
    passTime();
} // end grow()

// Adds 1 to number of veggies
void Vegetable::addVeggie() {
    veggies = veggies + 1;
} // end addVeggie()

// Removes all veggies, prints message notifying user
void Vegetable::harvestVeggies() {
    cout << "   * Harvested " << veggies << " veggies!";
    veggies = 0;
    cout << " Veggies = " << veggies << " *\n";
} // end harvestVeggies()
