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
        cout << setw(22) << right << "Plant Height = " << height << "\n";
        cout << setw(22) << "Water Level = " << waterLevel << "\n";
        cout << setw(22) << "Fertilizer Level = " << fertilizerLevel << "\n";
        cout << setw(22) << "Number of Weeds = " << weedCount<< "\n";
    } // end printStage()
    
    virtual void printCareOptions(int plantNumber) {
        cout << "\nCare Options for Plant " << plantNumber << ":\n"
             << "    0 - No Action\n"
             << "    1 - Water\n"
             << "    2 - Fertilize\n"
             << "    3 - Weed\n";
    }
    
    virtual int careFor(int plantNumber) {
        cout << "I would like to take action number: ";
        int chosenAction;
        cin >> chosenAction; // SHOULD THIS BE A WORD NOT AN INT?
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
        return chosenAction;
    }
    
    void addWater() {
        waterLevel = waterLevel + 2;
        cout << "   * Watered the plant! Water = " << waterLevel << " *\n";
    } // end water()

    void removeWeed() {
        weedCount = weedCount - 1;
        cout << "   * Weeded the plant! Weed = " << weedCount << " *\n";
    } // end removeWeed()
    
    void addFertilizer() {
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
    int fertilizerLevel;
    int weedCount;
    int height;
};

#endif /* PLANT_H */
