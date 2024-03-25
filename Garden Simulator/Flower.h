/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Flower.H

*/

#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h" // Include the base class

// Flower derived class declaration
class Flower : public Plant {

public:
    
    // CONSTRUCTOR
    Flower(string enteredName); // creates a flower, sets name, and initializes other values to 0, prints message notifying user of planted flower
    
    // Using base class function, prints plant stats, then prints blooms
    virtual void printStage();

    // Using base class function, prints plant care options, then prints Cut Blooms
    virtual void printCareOptions(int plantNumber);
    
    // Using base class function, calls printCareOptions(), gets user's choice of action and calls that action
    virtual int careFor(int plantNumber);
    
    // Adds height and blooms if conditions are ideal for flower
    virtual void grow();

    // Adds 1 to number of blooms
    void addBloom();
    
    // Removes all blooms, prints message notifying user
    void cutBlooms();
    

private:
    int blooms; // the number of blooms the flower currently has
};

#endif /* FLOWER_H */
