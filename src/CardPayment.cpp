/* CardPayment.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the derived class methods defined in the CardPayment.h header file
*/

#include "CardPayment.h"


#include "CardPayment.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*  -----   Public Class Functions -----     */
void CardPayment::getPaymentDetails() {  //the PrintDetails is implemented here in the derived class

    cout << "----- " <<  getCardTypeDesc(cardType) << " Card Payment";
}

/*  -----   Public Getter & Setter Functions -----     */
int CardPayment::getCardType(){
    return cardType; //return the integer value corresponding to the currency type
}

void CardPayment::setCardType(int valToSet){
    cardType = valToSet;
}


string CardPayment::getCardTypeDesc(int cardType){
    if (cardType == 1)
        return "Credit";
    if (cardType == 2)
        return "Debit";
    // Just in case we add a new item in the future and forget to update this function
    return "Unknown";
}
