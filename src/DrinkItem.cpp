/* DrinkItem.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the derived class methods defined in the DrinkItem.h header file
*/
#include "DrinkItem.h"
#include "Helper.h"
#include <iomanip>

using namespace special_functions;


/*  -----   Public Class Functions -----     */
 void DrinkItem::printItemDetails() { //the overridden PrintDetails is implemented here
    cout << "Drink Item: " << getItemName() << " - " << "$" << std::fixed << std::setprecision(2) << getItemPrice()
    << " Size: " << getSize() << endl;

    if (alcoholic) {
        cout << "     - Alcoholic Beverage" << endl;
    } else {
        cout << "     - Non-alcoholic Beverage" << endl;
    }

    lineBreak(1);
}

/*  -----   Public Getter & Setter Functions -----     */
string DrinkItem::getSize(){
    return size;
}

bool DrinkItem::getAlcohol(){
    return alcoholic;
}


