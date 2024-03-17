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
#include <time.h>


using std::cout;
using std::cin;
using std::setw;
using std::right;

class Plant {
    
public:
    
    // CONSTRUCTOR
    Plant()
    : height{0}, waterLevel{0}, weedCount{0}, fertilizerLevel{0} {
        cout << "Planted ";
    } // end Plant() constructor
    
    const int getWaterLevel() {
        return waterLevel;
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
        cout << " - A plant grew!\n";
    }
    
    virtual void printStage() {
        // REORDER THESE
        cout << setw(22) << right << "Plant Height = " << height << "\n";
        cout << setw(22) << "Water Level = " << waterLevel << "\n";
        cout << setw(22) << "Number of Weeds = " << weedCount<< "\n";
        cout << setw(22) << "Fertilizer Level = " << fertilizerLevel << "\n";
    } // end printStage()
    
    virtual void careFor() = 0; // eventually turn this into a printCareFor and getCareFor and make base implementation
    
    void addWater() {
        waterLevel = waterLevel + 2;
        cout << "   * Watered the plant! Water = " << waterLevel << " *\n";
    } // end water()

    void removeWeed() {
        weedCount = weedCount - 1;
        cout << "   * Weeded the plant! Weed = " << weedCount << " *\n";
    } // end removeWeed()
    
    void addFertilize() {
        fertilizerLevel = fertilizerLevel + 2;
        cout << "   * Fertilized the plant! Fertilizer Level = " << fertilizerLevel << " *\n";
    } // end fertilize()
    
    void addWeed() {
        weedCount = weedCount + 1;
        cout << " - A weed grew!\n";
    }
    
    virtual void grow() = 0;
    
    void passTime() {
        srand((int)time(0));
        waterLevel = waterLevel - 1;
        if (rand() % 2 == 0 && fertilizerLevel > 0) {
            fertilizerLevel = fertilizerLevel - 1;
        }
        if (rand() % 3 == 0) {
            addWeed();
        }
    }
    
    
private:
    int waterLevel;
    int weedCount;
    int fertilizerLevel;
    int height;
};

#endif /* PLANT_H */
