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

#ifndef FLOWER_H
#define FLOWER_H

#include <stdio.h>
#include "Plant.h"

class Flower : public Plant {
    
public:
    // CONSTRUCTOR
    Flower()
    : maxFlowerSize{3} {
        
    } // end Flower() constructor
    
    
    
private:
    int maxFlowerSize;
    
    
};


#endif /* FLOWER_H */
