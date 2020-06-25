/* CashPayment.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Derived CashPayment Class
*/


#ifndef PIZZASHOPAPP_CASHPAYMENT_H
#define PIZZASHOPAPP_CASHPAYMENT_H

#include "Payment.h"

class CashPayment : public Payment { //Start derived class definition

public:
/*  -----   Public class constructor  -----     */
    CashPayment(int paymentTypeInp = 1, bool isValidatedInp = false, int currencyTypeInp = 1):
            Payment(paymentTypeInp,isValidatedInp),
            currencyType{currencyTypeInp} {   // Start Constructor body

    }

    /*  -----   Public Class Functions -----     */
    virtual void getPaymentDetails() override; //pure virtual function gets implemented in this derived class

    /*  -----   Public Getter & Setter Functions -----     */
    int getCurrencyType();
    string getCurrencyTypeDesc(int currencyType);
    void setCurrencyType(int valToSet);


private:
    int currencyType;
};

#endif //PIZZASHOPAPP_CASHPAYMENT_H
