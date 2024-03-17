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
#include "Flower.h" // SHOULD THIS BE INCLUDED HERE? WHERE?

using std::vector;


int main() {
    const int MAX_WEEKS = 10;
    
    // Plant a flower
    Flower sunflower;
    Plant * sunflowerPtr{&sunflower};
    
    // Plant a vegetable
    
    // Plant a tree
    
    // Instantiate garden as an array
    vector <Plant*> myGarden = {sunflowerPtr};

    
    // Days to pass
    for (int week = 1; week <= MAX_WEEKS; week++) {
        cout << "\n\n---------- Week " << week << " ----------\n";
        // Print garden
        for (int currentPlant = 0; currentPlant < myGarden.size(); currentPlant++) {
            cout << "Plant #" << currentPlant + 1 << ":\n";
            myGarden[currentPlant]->printStage();
            myGarden[currentPlant]->careFor();
            myGarden[currentPlant]->grow(); // may need to move this to its own for loop?
        }
    }
    
    // FINAL MESSAGE?
    
    cout << "\n\n";
    
}
