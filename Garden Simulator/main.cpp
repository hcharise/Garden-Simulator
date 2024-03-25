/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.
 
Main.CPP

*/


#include <iostream> // For inputting and outputting to user
#include <vector> // For creating a Plant vector to iterate through

#include "Plant.h" // Contains the details of the Plant base class
#include "Flower.h" // Contains the details of the Flower derived class
#include "Vegetable.h" // Contains the details of the Vegetable derived class
#include "Shrub.h" // Contains the details of the Shrub derived class

using std::vector; // For creating a Plant vector

// Test program for the Plant and derived classes
int main() {
    
    const int MAX_WEEKS = 5; // Number of weeks/repetitions
    
    // Print the intro banner
    cout << "----------------------------------------------------\n"
         << "             Garden-Like-A-Granny Game              "
        << "----------------------------------------------------\n\n";
    
    // Plant a flower and create pointer to it
    Flower sunflower("Sunflower");
    Plant * sunflowerPtr{&sunflower};
    
    // Plant a vegetable and create pointer to it
    Vegetable pepper("Pepper");
    Plant * pepperPtr{&pepper};
    
    // Plant a shrub and create pointer to it
    Shrub boxwood("Boxwood");
    Plant * boxwoodPtr{&boxwood};
    
    // Instantiate garden as an array of pointers to each plant
    vector <Plant*> myGarden = {sunflowerPtr, pepperPtr, boxwoodPtr};

    
    // Repeat for each week
    for (int week = 1; week <= MAX_WEEKS; week++) {
        
        // Print week header
        cout << "\n---------------------- WEEK " << week << " ----------------------\n";
        
        // Iterate through garden, printing each plant
        for (int currentPlant = 0; currentPlant < myGarden.size(); currentPlant++) {
            cout << "\nPLANT #" << currentPlant + 1 << ": "
            << myGarden[currentPlant]->getPlantName() << "\n";
            myGarden[currentPlant]->printStage();
        }
        
        // Iterate through garden, allowing user to care for each plant, then letting the plant grow
        for (int currentPlant = 0; currentPlant < myGarden.size(); currentPlant++) {
            myGarden[currentPlant]->careFor(currentPlant + 1);
            myGarden[currentPlant]->grow();
        }
    }
    
    // Print final message and garden status
    cout << "\n\n------------------------ END -----------------------\n";
    
    // Iterate through garden, printing each plant
    for (int currentPlant = 0; currentPlant < myGarden.size(); currentPlant++) {
        cout << "\nPLANT #" << currentPlant + 1 << ":\n";
        myGarden[currentPlant]->printStage();
    }

    cout << "\nGreat gardening!\n\n";
    
} // end main()
