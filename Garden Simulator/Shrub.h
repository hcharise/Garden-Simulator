/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
Final Project - Demonstration of Inheritance and Polymorphism
Garden Simulator
3/26/2024
 
 This program simulates a garden, allowing the user to care for and grow various plant types. The Plant class is a base class, with derived classes for Flowers, Vegetables, and Shrubs. Each of the derived classes has modified data members and member functions to monitor and adjust the plant's health, such as watering, harvesting, etc. The program's main file simulates the passing of time for a given number of weeks, printing the garden's current state each week before allowing the user to care for their plants as needed.

Shrub.H

*/

#ifndef SHRUB_H
#define SHRUB_H

#include "Plant.h" // Include the base class

// Shrub derived class declaration
class Shrub : public Plant {

public:
    
    // CONSTRUCTOR
    Shrub(string enteredName); // createes a shrub, sets name, and initilizes other values to 0, prints message notifying user of planted shrub
    
    // Using base class function, prints plant stats, then prints branches
    virtual void printStage();

    // Using base class function, prints plant care options, then prints Prune Branches
    virtual void printCareOptions(int plantNumber);
    
    // Using base class function, calls printCareOptions(), gets user's choice of action and calls that action
    virtual int careFor(int plantNumber);
    
    // Adds height and branches if conditions are ideal for shrub
    virtual void grow();

    // Adds 1 to number of branches
    void addBranch();
    
    // Removes all branches, prints message notifying user
    void pruneBranches();
    

private:
    int branches; // the number of branches the shrub currently has
};

#endif /* BRANCHES_H */
