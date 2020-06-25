/* Menu.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Menu Class
*/

#ifndef PIZZASHOPAPP_MENU_H
#define PIZZASHOPAPP_MENU_H

#include <string>
#include <vector>
#include "Order.h"


using std::string;
using std::vector;

class Menu { //Start class definition

public:

    /*  -----   Enumerated Menu Types Defined -----     */
    enum menuTypes {
        UNKNOWN = -1,
        DEFAULT = 0,
        DINE = 1,
        TAKEOUT = 2,
        DELIVERY = 3
    };

    /*  -----   Public class constructor  -----     */

    Menu (){   // Start Constructor body

        //Set the Menu Type - right now the shop has only 1 default menu
        setMenuType(DEFAULT);

        /*
         * Create a Default Menu
         * The Menu will consist of a vector of base class item pointers
        */

        createDefaultMenuItems(menuItems);

    } //End Constructor body

    /*  -----   Public Class Functions -----     */
    void printMenu ();
    void printMenu(int orderType); //Overloaded Print Menu function takes additional parameters
    void createDefaultMenuItems (vector <Item*> &menuItems);

    /*  -----   Public Getter & Setter Functions -----     */
    int getMenuType();
    vector <Item*> getMenuItems();
    Item* getMenuItem (int itemIndex);
    string getMenuTypeName(menuTypes type);

private:

    /*  -----    Private Data members  -----     */
    int menuType;
    vector <Item*> menuItems;

    /*  -----   Private Getter & Setter Functions -----     */
    void setMenuType(int menuTypeInp);


}; //end class definition

#endif //PIZZASHOPAPP_MENU_H
