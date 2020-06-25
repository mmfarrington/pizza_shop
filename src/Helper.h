/* Helper.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This defines the interface for the special helper functions - not associated with any classes
*/

#ifndef PIZZASHOPAPP_HELPER_H
#define PIZZASHOPAPP_HELPER_H

//New namespace to define generic helper functions separate from the class
namespace special_functions {

    /*  -----   Public Enum Message Types -----     */
    enum message { //enumerate the possible redirect message types

        MENU_REDIRECT = 1,
        ORDER_REDIRECT = 2,
        CART_REDIRECT = 3
    };

    /*
     * Name: validateCin
     * Description: helper function to validate the cin data type
     * Return Type: void
     */
    void validateCin(int valToCheck);

    /*
     * name: menuRedirect
     * Menu redirect function sends the user back to the main menu after making a selection or lets them exit
     * return type: void
     */
    void menuRedirect(int &selection, int messageType);

    /*
     * name: reset
     * helper function to run when an invalid cin value is provided
     * input: the cin value to reset
     * return type: void
     */

    void reset(int &cinVal);

    /*
     * name: lineBreak
     * helper function to insert line breaks
     * input: number of line breaks desired
     * return type: none
     */

    void lineBreak(int numLines);


    /*
     * name: printShopBanner
     * helper function to print the shop's logo banner
     * input: none
     * return type: none
     */

    void printBanner();

} // end namespace declaration

#endif //PIZZASHOPAPP_HELPER_H
