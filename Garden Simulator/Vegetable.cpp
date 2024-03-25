/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
DESCRIPTION
 
Main.CPP

*/

#include "Vegetable.h"

// CONSTRUCTOR
Vegetable::Vegetable(string enteredName)
: Plant(enteredName), veggies{0} {
    cout << "a vegetable called " << Plant::getPlantName() << "!\n";
} // end Vegetable() constructor

void Vegetable::printStage() {
    Plant::printStage();
    cout << setw(22) << "Number of Veggies = " << veggies << "\n";
} // end printStage()

void Vegetable::printCareOptions(int plantNumber) {
    Plant::printCareOptions(plantNumber);
    cout << "    4 - Harvest Veggies\n";
} // end printCareOptions()

int Vegetable::careFor(int plantNumber) {
    printCareOptions(plantNumber);
    int chosenAction = Plant::careFor(plantNumber);

    while (chosenAction != 0) {

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

void Vegetable::addVeggie() {
    veggies = veggies + 1;
} // end addVeggie()

void Vegetable::harvestVeggies() {
    cout << "   * Harvested " << veggies << " veggies!";
    veggies = 0;
    cout << " Veggies = " << veggies << " *\n";
} // end harvestVeggies()

void Vegetable::grow() {
    srand((int)time(0));
    if (getWeedCount() < 3 && getFertilizerLevel() > 1 && getFertilizerLevel() < 5 && getWaterLevel() > 2 && getWaterLevel() < 6) {
        addHeight(2);
        if (getHeight() > 3 && rand() % 2 == 0) {
            addVeggie();
        }
    }
    passTime();
} // end grow()
