/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
DESCRIPTION
 
Flower.H // NEED TO UPDATE THIS IN ALL FILES

*/

#ifndef FLOWER_H
#define FLOWER_H

#include <stdio.h>
#include "Plant.h"

class Flower : public Plant {

public:
    // CONSTRUCTOR
    Flower(string enteredName)
    : Plant(enteredName), blooms{0} {
        cout << "a flower called " << Plant::getPlantName() << "!\n";
    } // end Flower() constructor
    
    virtual void printStage() {
        Plant::printStage();
        cout << setw(22) << "Number of Blooms = " << blooms << "\n";
    } // end printStage()

    virtual void printCareOptions(int plantNumber) {
        Plant::printCareOptions(plantNumber);
        cout << "    4 - Cut Blooms\n";
    } // end printCareOptions()
    
    virtual int careFor(int plantNumber) {
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
    }
    
    void addBloom() {
        blooms = blooms + 1;
    }
    
    void cutBlooms() {
        cout << "   * Cut " << blooms << " blooms!";
        blooms = 0;
        cout << " Blooms = " << blooms << " *\n";
    }
    
    virtual void grow() {
        srand((int)time(0));
        if (getWeedCount() < 2 && getFertilizerLevel() > 0 && getFertilizerLevel() < 4 && getWaterLevel() > 1 && getWaterLevel() < 5) {
            addHeight(1);
            if (getHeight() > 2 && rand() % 3 == 0) {
                addBloom();
            }
        }
        passTime();
    }

private:
    int blooms;
};

#endif /* FLOWER_H */
