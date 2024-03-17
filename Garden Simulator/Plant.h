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
#include <iomanip>


using std::cout;
using std::cin;
using std::setw;
using std::right;

class Plant {
    
public:
    
    // CONSTRUCTOR
    Plant()
    : height{0}, dampness{0}, weedCount{0}, fertilizerLevel{0} {
        cout << "Planted ";
    } // end Plant() constructor
    
    const int getDampness() {
        return dampness;
    }
    const int getFertilizerLevel() {
        return fertilizerLevel;
    }
    const int getWeedCount() {
        return weedCount;
    }
    const int getHeight() {
        return height;
    }
    
    void addHeight(int additionalHeight) {
        height = height + additionalHeight;
    }
    
    virtual void printStage() {
        
        cout << setw(15) << right << "Height = " << height << "\n";
        cout << setw(15) << "Dampness = " << dampness << "\n";
        cout << setw(15) << "Weeds = " << weedCount<< "\n";
        cout << setw(15) << "Fertilizer = " << fertilizerLevel << "\n";
    } // end printStage()
    
    virtual void careFor() = 0; // eventually turn this into a printCareFor and getCareFor and make base implementation
    
    void addWater() {
        dampness = dampness + 1;
    } // end water()

    void removeWeed() {
        weedCount = weedCount - 1;
    } // end weed()
    
    void addFertilize() {
        fertilizerLevel = fertilizerLevel + 1;
    } // end fertilize()
    
    virtual void grow() = 0;
    
private:
    int dampness;
    int weedCount;
    int fertilizerLevel;
    int height;
};

#endif /* PLANT_H */
