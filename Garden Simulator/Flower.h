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

#ifndef FLOWER_H
#define FLOWER_H

#include <stdio.h>
#include "Plant.h"

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
        cout << setw(15) << "Blooms = " << blooms << "\n";
    } // end printStage()

    virtual void careFor() {
        int chosenAction;
        
        cout << "    1 - Water\n"
             << "    2 - Weed\n"
             << "    3 - Fertilize\n"
             << "    4 - Cut Blooms\n";
        cout << "How would you like to care for this flower? ";
        cin >> chosenAction;
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
                    break;
            }
            
            cout << "    1 - Water\n"
            << "    2 - Weed\n"
            << "    3 - Fertilize\n"
            << "    4 - Cut Blooms\n"
            << "    0 - Exit\n";
            cout << "How would you like to care for this flower? ";
            cin >> chosenAction;
        }
        
    } // end printStage()
    
    void addBloom() {
        blooms = blooms + 1;
    }
    
    void cutBlooms() {
        cout << "Cut " << blooms << " blooms!";
        blooms = 0;
    }
    
    virtual void grow() {
        if (getWeedCount() == 0 && getFertilizerLevel() > 0 && getDampness() > 0) {
            addHeight(1);
            if (getHeight() > 2) {
                addBloom();
            }
        }
    }

    
private:
    int blooms;
};


#endif /* FLOWER_H */
