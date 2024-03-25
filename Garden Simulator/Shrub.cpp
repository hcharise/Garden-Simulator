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

#include "Shrub.h"

// CONSTRUCTOR
Shrub::Shrub(string enteredName)
: Plant(enteredName), branches{0} {
    cout << "a shrub called " << Plant::getPlantName() << "!\n";
} // end Shrub() constructor

void Shrub::printStage() {
    Plant::printStage();
    cout << setw(22) << "Number of Branches = " << branches << "\n";
} // end printStage()

void Shrub::printCareOptions(int plantNumber) {
    Plant::printCareOptions(plantNumber);
    cout << "    4 - Prune Branches\n";
} // end printCareOptions()

int Shrub::careFor(int plantNumber) {
    printCareOptions(plantNumber);
    int chosenAction = Plant::careFor(plantNumber);

    while (chosenAction != 0) {

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

void Shrub::addBranch() {
    branches = branches + 1;
} // end addBranch()

void Shrub::pruneBranches() {
    cout << "   * Pruned " << branches << " brances!";
    branches = 0;
    cout << " Branches = " << branches << " *\n";
} // end pruneBranches()

void Shrub::grow() {
    srand((int)time(0));
    if (getWeedCount() < 4 && getFertilizerLevel() > -1 && getFertilizerLevel() < 6 && getWaterLevel() > 0 && getWaterLevel() < 8) {
        addHeight(2);
        if (getHeight() > 2 && rand() % 2 == 0) {
            addBranch();
        }
    }
    passTime();
} // end grow()
