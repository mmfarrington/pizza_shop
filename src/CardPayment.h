/* CardPayment.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Derived CardPayment Class
*/

#ifndef PIZZASHOPAPP_CARDPAYMENT_H
#define PIZZASHOPAPP_CARDPAYMENT_H

#include "Payment.h"

/*  -----   Public Enum Payment Data -----     */
enum  cardTypes
{
    //Shop only takes 2 types of cards
    CREDIT = 1,
    DEBIT = 2,
};

class CardPayment : public Payment { //Start derived class definition

    //End Constructor body

    /*  -----   Public Class Functions -----     */
    virtual void getPaymentDetails() override; //pure virtual function gets implemented in this derived class

    /*  -----   Public Getter & Setter Functions -----     */
    int getCardType();
    string getCardTypeDesc(int cardType);
    void setCardType(int valToSet);

public:
/*  -----   Public class constructor  -----     */
CardPayment(int paymentTypeInp = 1, bool isValidatedInp = false,  int cardTypeInp = 0):
        Payment(paymentTypeInp,isValidatedInp),
        cardType{cardTypeInp} {   // Start Constructor body

}

private:
    int cardType;

};

#endif //PIZZASHOPAPP_CARDPAYMENT_H
