/* FoodItem.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the derived class methods defined in the FoodItem.h header file
*/

#include "FoodItem.h"
#include "Helper.h"
#include <iostream>
#include <iomanip>

using namespace special_functions;
using std::cin;
using std::cout;
using std::endl;

/*  -----   Public Class Functions -----     */
void FoodItem::printItemDetails() { //the overridden PrintDetails is implemented here

    cout << "Food Item: " << getItemName() << " - " << "$" << std::fixed << std::setprecision(2) << getItemPrice() << endl;

    if (vegetarian){
        cout << "     - Vegetarian item" << endl;
    }

    if (glutenFree) {
        cout << "     - Gluten free item" << endl;
    }

    lineBreak(1);
}

/*  -----   Public Getter & Setter Functions -----     */
bool FoodItem::getVegetarian(){
    return vegetarian;
}
bool FoodItem::getGlutenFree(){
    return glutenFree;
}

int FoodItem::getItemType(){
    return itemType;
}


