/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Vegetable.H

*/

#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "Plant.h"

// Vegetable derived class declaration
class Vegetable : public Plant {

public:
    // CONSTRUCTOR
    Vegetable(string enteredName); // creates a vegetable, sets name, and initializes other valuees to 0, prints message notifying user of planted vegetable
    
    // Using base class function, prints plant stats, then prints harvest
    virtual void printStage();

    // Using base calss function, prints plant care options, then prints Harvest Vegetables
    virtual void printCareOptions(int plantNumber);
    
    // Using base class function, calls printCareOptions(), gets user's choice of action and calls that action
    virtual int careFor(int plantNumber);
    
    // Adds height and veggies if conditions are idea for vegetable
    virtual void grow();
    
    // Adds 1 to number of veggiees
    void addVeggie();
    
    // Removes all veggies, prints message notifying user
    void harvestVeggies();
    

private:
    int veggies; // the number of veggies the vegetable currently has harvestable
};

#endif /* VEGETABLE_H */
