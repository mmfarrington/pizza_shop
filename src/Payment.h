/* Payment.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Payment Class
*/


#ifndef PIZZASHOPAPP_PAYMENT_H
#define PIZZASHOPAPP_PAYMENT_H

#include <string>

using std::string;

class Payment { //Start abstract class definition

public:

    /*  -----   Enumerated Payment Types Defined -----     */
    enum paymentTypes
    {
        UNKNOWN = -1,
        DEFAULT = 0,
        CASH = 1,
        CARD = 2,
    };

    /*  -----   Public class constructor  -----     */
    Payment (int paymentTypeInp = DEFAULT, bool isValidatedInp = false):
    paymentType{paymentTypeInp}, isValidated{isValidatedInp} {   // Start Constructor body

    } //End Constructor body

    /*  -----   Public Getter & Setter Functions -----     */
    virtual void getPaymentDetails() = 0; //pure  virtual function
    string getPaymentTypeDesc(int paymentType);
    int getPaymentType();
    void setValidation(bool validToSet);
    bool getValidation();

/*  -----   Private Getter & Setter Functions -----     */
void setPaymentType(int typeToSet);

private:
    string paymentTypeDesc;
    bool isValidated;
    void setPaymentTypeDesc(paymentTypes desc);

protected:
/*  -----    Private Data members  -----     */
int paymentType;

}; //end class definition

#endif //PIZZASHOPAPP_PAYMENT_H
