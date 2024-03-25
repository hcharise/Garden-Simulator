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

#include "Plant.h"

class Flower : public Plant {

public:
    // CONSTRUCTOR
    Flower(string enteredName);
    
    virtual void printStage();

    virtual void printCareOptions(int plantNumber);
    
    virtual int careFor(int plantNumber);
    
    void addBloom();
    
    void cutBlooms();
    
    virtual void grow();

private:
    int blooms;
};

#endif /* FLOWER_H */
