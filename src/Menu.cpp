/* Menu.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the class methods defined in the Menu.h header file
*/

#include "Menu.h"
#include "FoodItem.h"
#include "DrinkItem.h"
#include "Helper.h"
#include "Item.h"
#include <iostream>
#include <zconf.h>

using namespace special_functions;
using std::cin;
using std::cout;
using std::endl;



/*  -----   Public Class Functions -----     */
void Menu::printMenu (){
    lineBreak(1);
    for (int i = 0; i < menuItems.size(); ++i)
    {
        int counter = i; //index for the menu list
        cout << ++counter << ") " ;
        menuItems[i]->printItemDetails(); //Polymorphic call from base class pointer to derived class functions!!
    }

    lineBreak(2);
    sleep(1);
}

void Menu::printMenu(int orderType){ //overloaded print function
    setMenuType(orderType); //set the menu based on what the customer picked

    lineBreak(1);
    cout << "\x1b[32m----- " << getMenuTypeName(static_cast<menuTypes>(menuType)) <<
         " Menu -----\x1b[0m" << endl;

    //ToDo: Modify this to allow for the ability to print custom menu types depending on the order type
    //call the default print menu function to complete
    printMenu();

}


void Menu::createDefaultMenuItems (vector <Item*> &menuItems){

    //Add derived class Food objects to the menuItems vector of base class Pointers
    menuItems.push_back(new FoodItem ("Cheese Pizza", 10.00, 1,true, false));
    menuItems.push_back(new FoodItem ("Gluten Free Cheese Pizza", 10.50, 1, true, true));
    menuItems.push_back(new FoodItem ("Pepperoni Pizza", 12.00));
    menuItems.push_back(new FoodItem ("Margherita Pizza", 11.00,  1, true));
    menuItems.push_back(new FoodItem ("Chicken Parm Pizza", 15.00, 1, true));

    //Add derived class Drink objects to the menuItems vector of base class Pointers
    menuItems.push_back(new DrinkItem ("Coca-Cola", 3.00, 2, "Large"));
    menuItems.push_back(new DrinkItem ("Pellegrino Water", 4.25,2, "Medium"));
    menuItems.push_back(new DrinkItem ("Red Wine", 6.00, 2,"NA", true));
    menuItems.push_back(new DrinkItem ("Beer", 5.00,2, "NA", true));

    //Todo: Add more derived class objects to the vector here!!
}

/*  -----   Public Getter & Setter Functions -----     */

int Menu::getMenuType(){
    if (menuType == DEFAULT ||
        menuType == DINE ||
        menuType == TAKEOUT ||
        menuType == DELIVERY) {
        return menuType;
    }

    return UNKNOWN; //unknown menu type
}

vector <Item*> Menu::getMenuItems(){

    return menuItems;
}

Item* Menu::getMenuItem (int itemIndex){

    return menuItems[itemIndex];
}

/*  -----   Public Getter & Setter Functions -----     */
string Menu::getMenuTypeName(menuTypes type){
    if (type == UNKNOWN)
        return "Unknown";
    if (type == DEFAULT)
        return "Default";
    if (type == DINE)
        return "Dine-In";
    if (type == TAKEOUT)
        return "Carry-out";
    if (type == DELIVERY)
        return "Delivery";
    // Just in case we add a new item in the future and forget to update this function
    return "Unknown";
}



/*  -----   Private Getter & Setter Functions -----     */

void Menu::setMenuType(int menuTypeInp){
        menuType = menuTypeInp;
}

