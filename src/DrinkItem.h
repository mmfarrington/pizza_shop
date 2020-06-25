/* DrinkItem.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Derived DrinkItem Class
*/

#ifndef PIZZASHOPAPP_DRINKITEM_H
#define PIZZASHOPAPP_DRINKITEM_H

#include <string>
#include "Item.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class DrinkItem : public Item {  //Start derived class definition

public:
    /*  -----   Public class constructor  -----     */
    DrinkItem(string itemNameInp,  double itemPriceInp, int itemTypeInp = 2, string sizeInp = "NA", bool alcInp = false) :
    Item(itemNameInp, itemPriceInp, itemTypeInp),  size{sizeInp}, alcoholic{alcInp}  {
    }

    /*  -----   Public Class Functions -----     */
    virtual void printItemDetails() override ; //the PrintDetails function will be implemented in the derived class

    /*  -----   Public Getter & Setter Functions -----     */
    string getSize();
    bool getAlcohol();


private:
    /*  -----    Private Data members  -----     */
    string size;
    bool alcoholic;


}; //End class definition


#endif //PIZZASHOPAPP_DRINKITEM_H
