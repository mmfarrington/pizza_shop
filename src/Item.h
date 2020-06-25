/* Item.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Item Class
*/

#ifndef PIZZASHOPAPP_ITEM_H
#define PIZZASHOPAPP_ITEM_H

#include <string>

using std::string;

class Item { //Start Abstract class definition

public:

    /*  -----   Enumerated Item Types Defined -----     */
    enum  itemTypes {
        UNKNOWN = -1,
        DEFAULT = 0,
        FOOD = 1,
        DRINK = 2
    };


    /*  -----   Public class constructor  -----     */
    Item (string itemNameInp, double itemPriceInp = 0.00, int itemQuantityInp = 1, int itemTypeInp = DEFAULT) :
     itemName{itemNameInp}, itemPrice{itemPriceInp},itemQuantity{itemQuantityInp}, itemType{itemTypeInp} {   // Start Constructor body

    } //End Constructor body

    /*  -----   Public Class Functions -----     */
    virtual void printItemDetails() = 0 ; //Virtual Function

    /*  -----   Public Getter & Setter Functions -----     */

    string getItemName();
    double getItemPrice();
    int getItemQuantity();
    int getItemType();

    void setItemName( string itemNameInp);
    void setItemPrice( double itemPriceInp);
    void setItemQuantity(int quantityInp);


    int itemType;
private:

    /*  -----    Private Data members  -----     */
    string itemName;
    double itemPrice;
    int itemQuantity;
    // distinguish between available types



}; //end class definition

#endif //PIZZASHOPAPP_ITEM_H
