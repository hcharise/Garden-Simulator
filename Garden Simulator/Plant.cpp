/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.
 
Plant.CPP

*/
#include "Plant.h"

// CONSTRUCTOR
// Creates an object of Plant class
// Takes in plant's name as parameter to initialize; all other data members intiailized to 0
Plant::Plant(string enteredName)
: plantName{enteredName}, height{0}, waterLevel{0}, weedCount{0}, fertilizerLevel{0} {
    cout << "Planted ";
} // end Plant() constructor

// GETTERS
// Returns the nam eof the plant
const string Plant::getPlantName() {
    return plantName;
} // end getPlantName()

// Returns the current height of the plant
const int Plant::getHeight() {
    return height;
} // end getHeight()

// Returns the current water level of the plant
const int Plant::getWaterLevel() {
    return waterLevel;
} // end getWaterLevel()

// Returns the current fertilizer level of the plant
const int Plant::getFertilizerLevel() {
    return fertilizerLevel;
} // end getFertilizerLevel()

// Returns the current weed count of the plant
const int Plant::getWeedCount() {
    return weedCount;
} // end getWeedCount()


// VIRTUAL, derived classes may modify
// Prints the plant's current stats (height, water, fertilizer, weeds)
void Plant::printStage() {
    cout << setw(22) << right << "Plant Height = " << height << "\n";
    cout << setw(22) << "Water Level = " << waterLevel << "\n";
    cout << setw(22) << "Fertilizer Level = " << fertilizerLevel << "\n";
    cout << setw(22) << "Number of Weeds = " << weedCount<< "\n";
} // end printStage()

// Prints the plant options the user has for caring for the plant
void Plant::printCareOptions(int plantNumber) {
    cout << "\nCare Options for Plant " << plantNumber << ":\n"
         << "    0 - No Action\n"
         << "    1 - Water\n"
         << "    2 - Fertilize\n"
         << "    3 - Weed\n";
} // end printCareOptions()

// Calls printCareOptions(), gets user's choice of action, and calls that action
// Returns the chosen action in case it is a derived-class specific choice
int Plant::careFor(int plantNumber) {
    
    // Get action choice from user
    cout << "I would like to take action number: ";
    int chosenAction;
    cin >> chosenAction;
    
    // Calls appropriate plant function/action
    switch (chosenAction) {
        case(1):
            addWater();
            break;
        case(2):
            addFertilizer();
            break;
        case(3):
            removeWeed();
            break;
        default:
            break;
    }
    return chosenAction; // returns value in case user chose derived-class-specific function
} // print careFor()

// OTHER
// Simulates the passing of time by removing water/fertilizer and adding weeds
void Plant::passTime() {
    srand((int)time(0));
    
    // Always removes water
    waterLevel = waterLevel - 1;
    
    // Sometimes (randomly) removes fertilizer
    if (rand() % 2 == 0 && fertilizerLevel > 0) {
        fertilizerLevel = fertilizerLevel - 1;
    }
    // Sometimes (randomly) adds a weed
    if (rand() % 3 == 0) {
        addWeed();
    }
} // end passTime()

// Increases the plant's height by the amount specified as a parameter
void Plant::addHeight(int additionalHeight) {
    height = height + additionalHeight;
} // end addHeight()

// Adds 1 to the water level
void Plant::addWater() {
    waterLevel = waterLevel + 2;
    cout << "   * Watered the plant! Water = " << waterLevel << " *\n";
} // end addWater()

// Adds 1 to the fertilizer level
void Plant::addFertilizer() {
    fertilizerLevel = fertilizerLevel + 2;
    cout << "   * Fertilized the plant! Fertilizer Level = " << fertilizerLevel << " *\n";
} // end addFertilizer()

// Adds 1 to the weed count
void Plant::addWeed() {
    weedCount = weedCount + 1;
} // end addWeed()

// Deletes 1 from the weed count and notifies user that it was weeded
void Plant::removeWeed() {
    weedCount = weedCount - 1;
    cout << "   * Weeded the plant! Weed = " << weedCount << " *\n";
} // end removeWeed()
