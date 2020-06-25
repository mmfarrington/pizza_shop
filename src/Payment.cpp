/* Payment.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the class methods defined in the Payment.h header file
*/

#include "Payment.h"



/*  -----   Public Getter & Setter Functions -----     */
string Payment::getPaymentTypeDesc(int paymentType){
    if (paymentType == 1)
        return "Credit Card Payment";
    if (paymentType == 2)
        return "Cash Payment";
    // Just in case we add a new item in the future and forget to update this function
    return "Unknown";
}

int Payment::getPaymentType() {
    if (paymentType == DEFAULT ||
        paymentType == CASH ||
        paymentType == CARD) {
        return paymentType;
    }

    return UNKNOWN; //unknown payment type
}

bool Payment::getValidation(){
    return isValidated;
}

/*  -----   Private Getter & Setter Functions -----     */
void Payment::setPaymentType(int typeToSet){
    paymentType = typeToSet;
}

void Payment::setValidation(bool validToSet){
    isValidated = validToSet;

}
void Payment::setPaymentTypeDesc(paymentTypes desc){
    paymentTypeDesc = getPaymentTypeDesc(desc);

}