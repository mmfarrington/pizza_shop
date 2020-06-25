/* Helper.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This contains the definitions of the special helper functions in the special_functions namespace
*/

#include "Helper.h"
#include <iostream>
#include <zconf.h>

using namespace special_functions; //importing the special_functions namespace

using std::cin;
using std::cout;
using std::endl;


/*
* Name: validateCin
* Description: helper function to validate the cin data type
* Return Type: void
*/

void special_functions::validateCin(int valToCheck) {

    while (cin.fail()) {
        // clear error state
        cin.clear();
        // discard 'bad' character(s)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\x1b[32m Invalid Entry. Please try again. \x1b[0m";
        cin >> valToCheck; //
    }
}
/*
     * name: menuRedirect
     * Menu redirect function sends the user back to the main menu after making a selection or lets them exit
     * return type: void
     */
void special_functions::menuRedirect(int &selection, int messageType) {
    cout << endl;

    if (messageType == MENU_REDIRECT ) {
        cout << "\x1b[31mTo return to the main Menu enter 0 or enter -1 to Exit: \x1b[0m" ;
    }
    if (messageType == ORDER_REDIRECT) {
        cout << "\x1b[31mTo continue adding to Order enter 0 or enter -1 to Exit: \x1b[0m" ;
    }
    if (messageType == CART_REDIRECT) {
        cout << "\x1b[31mTo return to the Main Menu to Checkout enter 0 or enter -1 to Exit: \x1b[0m" ;
    }

    cin >> selection;
    cout << endl;
    validateCin(selection);

    while (selection > 0) {
        reset(selection);
    }

}



/*
    * name: reset
    * helper function to run when an invalid cin value is provided
    * input: the cin value to reset
    * return type: void
    */
void special_functions::reset(int &cinVal){

    sleep(1);
    cinVal = 0; //reset
    cout << "\x1b[31mInvalid selection, please re-enter: \x1b[0m";
    cin >> cinVal; //read in the new value
    validateCin(cinVal); //check the new entered value is an integer

}

/*
     * name: lineBreak
     * helper function to insert line breaks
     * input: number of line breaks desired
     * return type: none
     */

void special_functions::lineBreak(int numLines){
    for (int i = 0; i < numLines; i++) {
        cout << endl;
    }
}


/*
     * name: printShopBanner
     * helper function to print the shop's logo banner
     * input: none
     * return type: none
     */

void special_functions::printBanner(){

    lineBreak(2);
    cout << "\x1b[32m___________________________________________________________________________________\x1b[0m" << endl;
    cout << "___________________________________________________________________________________" << endl;
    cout << "\x1b[31m___________________________________________________________________________________\x1b[0m" << endl;
    cout << endl;
    cout << "\x1b[32m ██████╗ ██╗███████╗███████╗ █████╗     ███████╗██╗  ██╗ ██████╗ ██████╗ \x1b[0m " << endl;
    cout << "\x1b[32m ██╔══██╗██║╚══███╔╝╚══███╔╝██╔══██╗    ██╔════╝██║  ██║██╔═══██╗██╔══██╗\x1b[0m " << endl;
    cout << "\x1b[32m ██████╔╝██║  ███╔╝   ███╔╝ ███████║    ███████╗███████║██║   ██║██████╔╝\x1b[0m " << endl;
    cout << "\x1b[32m ██╔═══╝ ██║ ███╔╝   ███╔╝  ██╔══██║    ╚════██║██╔══██║██║   ██║██╔═══╝\x1b[0m " << endl;
    cout << "\x1b[32m ██║     ██║███████╗███████╗██║  ██║    ███████║██║  ██║╚██████╔╝██║\x1b[0m " << endl;
    cout << "\x1b[32m ╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝    ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝\x1b[0m " << endl;
    cout << endl;
    cout << "\x1b[32m___________________________________________________________________________________\x1b[0m" << endl;
    cout << "___________________________________________________________________________________" << endl;
    cout << "\x1b[31m___________________________________________________________________________________\x1b[0m" << endl;
    lineBreak(2);
}