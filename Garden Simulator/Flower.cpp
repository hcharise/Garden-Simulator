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

#include "Flower.h"

// CONSTRUCTOR
Flower::Flower(string enteredName)
: Plant(enteredName), blooms{0} {
    cout << "a flower called " << Plant::getPlantName() << "!\n";
} // end Flower() constructor

void Flower::printStage() {
    Plant::printStage();
    cout << setw(22) << "Number of Blooms = " << blooms << "\n";
} // end printStage()

void Flower::printCareOptions(int plantNumber) {
    Plant::printCareOptions(plantNumber);
    cout << "    4 - Cut Blooms\n";
} // end printCareOptions()

int Flower::careFor(int plantNumber) {
    printCareOptions(plantNumber);
    int chosenAction = Plant::careFor(plantNumber);

    while (chosenAction != 0) {

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

void Flower::addBloom() {
    blooms = blooms + 1;
} // end addBloom()

void Flower::cutBlooms() {
    cout << "   * Cut " << blooms << " blooms!";
    blooms = 0;
    cout << " Blooms = " << blooms << " *\n";
} // end cutBlooms()

void Flower::grow() {
    srand((int)time(0));
    if (getWeedCount() < 2 && getFertilizerLevel() > 0 && getFertilizerLevel() < 4 && getWaterLevel() > 1 && getWaterLevel() < 5) {
        addHeight(1);
        if (getHeight() > 2 && rand() % 3 == 0) {
            addBloom();
        }
    }
    passTime();
} // end grow()
