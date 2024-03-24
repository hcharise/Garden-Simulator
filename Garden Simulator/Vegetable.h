/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
DESCRIPTION
 
Vegetable.H // NEED TO UPDATE THIS IN ALL FILES

*/

#ifndef VEGETABLE_H
#define VEGETABLE_H

#include <stdio.h>
#include "Plant.h"

// GET RID OF MAGIC NUMBERS

class Vegetable : public Plant {

public:
    // CONSTRUCTOR
    Vegetable(string enteredName)
    : Plant(enteredName), veggies{0} {
        cout << "a vegetable called " << Plant::getPlantName() << "!\n";
    } // end Vegetable() constructor
    
    virtual void printStage() {
        Plant::printStage();
        cout << setw(22) << "Number of Veggies = " << veggies << "\n";
    } // end printStage()

    virtual void printCareOptions(int plantNumber) {
        Plant::printCareOptions(plantNumber);
        cout << "    4 - Harvest Veggies\n";
    } // end printCareOptions()
    
    virtual int careFor(int plantNumber) {
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
    }
    
    void addVeggie() {
        veggies = veggies + 1;
    }
    
    void harvestVeggies() {
        cout << "   * Harvested " << veggies << " veggies!";
        veggies = 0;
        cout << " Veggies = " << veggies << " *\n";
    }
    
    virtual void grow() {
        srand((int)time(0));
        if (getWeedCount() < 3 && getFertilizerLevel() > 1 && getFertilizerLevel() < 5 && getWaterLevel() > 2 && getWaterLevel() < 6) {
            addHeight(2);
            if (getHeight() > 3 && rand() % 2 == 0) {
                addVeggie();
            }
        }
        passTime();
    }

private:
    int veggies;
};

#endif /* VEGETABLE_H */
