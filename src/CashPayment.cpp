/* CashPayment.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the derived class methods defined in the CashPayment.h header file
*/

#include "CashPayment.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*  -----   Public Class Functions -----     */
void CashPayment::getPaymentDetails() {  //the PrintDetails is implemented here in the derived class

     cout << "----- Cash Payment " << "in "
     << getCurrencyTypeDesc(currencyType);
}

/*  -----   Public Getter & Setter Functions -----     */
int CashPayment::getCurrencyType(){
    return currencyType; //return the integer value corresponding to the currency type
}

void CashPayment::setCurrencyType(int valToSet){
    currencyType = valToSet;
}

string CashPayment::getCurrencyTypeDesc(int currencyType){
    if (currencyType == 1)
        return "US Dollar";
    if (currencyType == 2)
        return "Canadian Dollar";
    // Just in case we add a new item in the future and forget to update this function
    return "Unknown";
}
