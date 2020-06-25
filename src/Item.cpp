/* Item.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the class methods defined in the Item.h header file
*/

#include "Item.h"

/*  -----   Public Getter & Setter Functions -----     */


string Item::getItemName(){
    return itemName;
}


double Item::getItemPrice(){
    return itemPrice;
}

int Item::getItemQuantity(){
    return itemQuantity;
}

int Item::getItemType() {
    if (itemType == DEFAULT || itemType == FOOD || itemType == DRINK) {
        return itemType;
    }

        return UNKNOWN; //unknown item type being retrieved
}

/*  -----   Private Getter & Setter Functions -----     */

void Item::setItemName( string itemNameInp){
    itemName = itemNameInp;
}

void Item::setItemPrice(double itemPriceInp){
    itemPrice = itemPriceInp;
}

void Item::setItemQuantity( int quantityInp){
    itemQuantity = quantityInp;
}
