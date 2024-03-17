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

    virtual void careFor() {
        int chosenAction;
        
        cout << "\nWould you like to care for this flower?\n"
             << "    0 - No Action\n"
             << "    1 - Water\n"
             << "    2 - Weed\n"
             << "    3 - Fertilize\n"
             << "    4 - Cut Blooms\n"
             << "I would like to take action number: ";
        cin >> chosenAction; // SHOULD THIS BE A WORD NOT AN INT?
        while (chosenAction != 0) {
            
            switch (chosenAction) {
                case(1):
                    addWater();
                    break;
                case(2):
                    removeWeed();
                    break;
                case(3):
                    addFertilize();
                    break;
                case(4):
                    cutBlooms();
                    break;
                default:
                    cout << "   * Another week goes by! * ";
                    break;
            }
            cout << "I would like to take action number: ";
            cin >> chosenAction;
        }
        
    } // end printStage()
    
    void addBloom() {
        blooms = blooms + 1;
        cout << " - A bloom grew!";
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
