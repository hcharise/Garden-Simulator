/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
DESCRIPTION
 
Shrub.H // NEED TO UPDATE THIS IN ALL FILES

*/

#ifndef SHRUB_H
#define SHRUB_H

#include <stdio.h>
#include "Plant.h"

class Shrub : public Plant {

public:
    // CONSTRUCTOR
    Shrub(string enteredName)
    : Plant(enteredName), branches{0} {
        cout << "a shrub called " << Plant::getPlantName() << "!\n";
    } // end Shrub() constructor
    
    virtual void printStage() {
        Plant::printStage();
        cout << setw(22) << "Number of Branches = " << branches << "\n";
    } // end printStage()

    virtual void printCareOptions(int plantNumber) {
        Plant::printCareOptions(plantNumber);
        cout << "    4 - Prune Branches\n";
    } // end printCareOptions()
    
    virtual int careFor(int plantNumber) {
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
    }
    
    void addBranch() {
        branches = branches + 1;
    }
    
    void pruneBranches() {
        cout << "   * Pruned " << branches << " brances!";
        branches = 0;
        cout << " Branches = " << branches << " *\n";
    }
    
    virtual void grow() {
        srand((int)time(0));
        if (getWeedCount() < 4 && getFertilizerLevel() > 0 && getFertilizerLevel() < 6 && getWaterLevel() > 0 && getWaterLevel() < 8) {
            addHeight(2);
            if (getHeight() > 2 && rand() % 2 == 0) {
                addBranch();
            }
        }
        passTime();
    }

private:
    int branches;
};

#endif /* BRANCHES_H */
