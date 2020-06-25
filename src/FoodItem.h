/* FoodItem.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Derived FoodItem Class
*/

#ifndef PIZZASHOPAPP_FOODITEM_H
#define PIZZASHOPAPP_FOODITEM_H

#include "Item.h"


class FoodItem : public Item { //Start derived class definition

public:

    /*  -----   Public class constructor  -----     */
    FoodItem(string itemNameInp, double itemPriceInp, int itemTypeInp=1, bool vegInp = false, bool glutenInp = false) :
    Item(itemNameInp, itemPriceInp, itemTypeInp), vegetarian{vegInp}, glutenFree{glutenInp}  {
    }

    /*  -----   Public Class Functions -----     */
    virtual void printItemDetails() override; //the PrintDetails function will be implemented in the derived class

    /*  -----   Public Getter & Setter Functions -----     */
    bool getVegetarian();
    bool getGlutenFree();
    int getItemType();

private:
    /*  -----    Private Data members  -----     */
    bool vegetarian;
    bool glutenFree;

}; //End class definition

#endif //PIZZASHOPAPP_FOODITEM_H
