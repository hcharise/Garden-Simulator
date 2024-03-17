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

#ifndef PLANT_H
#define PLANT_H

#include <iostream>

using std::cout;
using std::cin;


class Plant {
    
public:
    
    // CONSTRUCTOR
    Plant()
    : age{0}, dampness{0} {
        cout << "Planted!\n";
    } // end Plant() constructor
    
    // GETTERS
    int getAge() const {
        return age;
    } // end getAge()
    
    int getDampness() const {
        return dampness;
    } // end getAge()
    
    
private:
    int age;
    int dampness;
    
};

#endif /* PLANT_H */
