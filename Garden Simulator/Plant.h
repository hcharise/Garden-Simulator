/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Plant.H

*/

#ifndef PLANT_H
#define PLANT_H

#include <iostream> // Used for getting input and printing output
#include <iomanip> // Used to format output
#include <time.h> // Used for seeding srand()

using std::string; // Used for string variables

// Used for getting input and printing output
using std::cout;
using std::cin;

// Used to format output
using std::setw;
using std::right;

// Abstract base class declaration
class Plant {
    
public:
    
    // CONSTRUCTOR
    Plant(string enteredName); // creates a plant and initializes values to 0
    
    // GETTERS
    const string getPlantName(); // returns the name of the plant
    
    const int getHeight(); // returns the height of the plant
    
    const int getWaterLevel(); // returns the water level of the plant
    
    const int getFertilizerLevel(); // returns the fertilizer level of the plant
    
    const int getWeedCount(); // returns the weed count of the plant
    
    // VIRTUAL, derived classes may modify
    virtual void printStage(); // prints the plant's current stats (height, water, fertilizer, weeds)
    
    virtual void printCareOptions(int plantNumber); // prints the options the user has for caring for the plant
    
    virtual int careFor(int plantNumber); // calls printCareOptions(), gets user's choice of action, and calls that action
    
    virtual void grow() = 0; // in derived classes, will include directions on how/when plant grows; pure virutal function
    
    // OTHER
    void passTime(); // simulates the passing of time by removing water/fertilizer and adding weeds
    
    void addHeight(int additionalHeight); // increases the plant's height by the amount specified as a parameter
    
    void addWater(); // adds 1 to the water level, prints message notifying user

    void addFertilizer(); // adds 1 to the fertilizer level, prints message notifying user
    
    void addWeed(); // adds 1 to the weed count
    
    void removeWeed(); // deletes 1 from the weed count, prints message notifying user
    
private:
    const string plantName; // the name of the plant
    int height; // the current height of the plant
    int waterLevel; // the amount of water the plant currently has
    int fertilizerLevel; // the amount of fertilizer the plant currently has
    int weedCount; // the number of weeds the plant currently has
};

#endif /* PLANT_H */
