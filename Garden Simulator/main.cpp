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


#include <iostream>
#include <vector>

#include "Plant.h"
#include "Flower.h"
#include "Vegetable.h"
#include "Shrub.h"

using std::vector;


int main() {
    const int MAX_WEEKS = 5;
    
    cout << "----------------------------------------------------\n"
         << "             Garden-Like-A-Granny Game              "
        << "----------------------------------------------------\n\n";
    
    // Plant a flower
    Flower sunflower("Sunflower");
    Plant * sunflowerPtr{&sunflower};
    
    // Plant a vegetable
    Vegetable pepper("Pepper");
    Plant * pepperPtr{&pepper};
    
    // Plant a shrub
    Shrub boxwood("Boxwood");
    Plant * boxwoodPtr{&boxwood};
    
    // Instantiate garden as an array
    vector <Plant*> myGarden = {sunflowerPtr, pepperPtr, boxwoodPtr};

    
    // Days to pass
    for (int week = 1; week <= MAX_WEEKS; week++) {
        cout << "\n---------------------- WEEK " << week << " ----------------------\n";
        // Print garden
        for (int currentPlant = 0; currentPlant < myGarden.size(); currentPlant++) {
            cout << "\nPLANT #" << currentPlant + 1 << ": "
                 << myGarden[currentPlant]->getPlantName() << "\n";
            myGarden[currentPlant]->printStage();
            myGarden[currentPlant]->careFor(currentPlant + 1);
            myGarden[currentPlant]->grow();
        }
    }
    
    cout << "\n\n------------------------ END -----------------------\n";
    for (int currentPlant = 0; currentPlant < myGarden.size(); currentPlant++) {
        cout << "\nPLANT #" << currentPlant + 1 << ":\n";
        myGarden[currentPlant]->printStage();
    }
    cout << "\nGreat gardening!\n\n";
    
}
