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

// GET RID OF MAGIC NUMBERS

class Flower : public Plant {
    
public:
    // CONSTRUCTOR
    Flower()
    : blooms{0} {
        cout << "a flower!\n";
        // SHOULD THE FLOWER KNOW IT'S NAME?
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
        cout << " - A bloom grew!\n";
    }
    
    void cutBlooms() {
        blooms = 0;
        cout << "   * Cut blooms! Blooms = " << blooms << " *\n";
    }
    
    virtual void grow() {
        srand((int)time(0));
        cout << "\nThroughout the week:\n"; // SHOULD THIS BE HERE?
        // COULD REFINE THESE RANGES
        if (getWeedCount() < 2 && getFertilizerLevel() > 0 && getWaterLevel() > 0) {
            addHeight(1); // SHOULD THERE BE A MAX HEIGHT?
            if (getHeight() > 2 && rand() % 2 == 0) {
                addBloom();
            }
        } else if (rand() % 5 == 0){
            cout << " - A plant died!! :'(\n"; // NEED TO DECONSTRUCT? WHAT HAPPENS TO VECTOR?
        }
        passTime();
    }

    
private:
    int blooms;
};


#endif /* FLOWER_H */
