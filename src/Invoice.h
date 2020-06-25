/* Invoice.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Invoice Class
*/


#ifndef PIZZASHOPAPP_INVOICE_H
#define PIZZASHOPAPP_INVOICE_H

#include "Order.h"

class Invoice { //Start class definition

public:


    /*  -----   Enumerated Types Defined -----     */
    enum  invoiceTypes {
        DEFAULT = 0,
    };


    /*  -----   Public class constructor  -----     */
    Invoice (Order orderInp)
    : order{orderInp} {   // Start Constructor body

        //initialize private variables to 0
        setTotalPrice(DEFAULT);
        setSubtotalPrice(DEFAULT);
        setTaxRate(DEFAULT);
        setTaxAmt(DEFAULT);

    } //End Constructor body

    /*  -----   Public Class Functions -----     */
    void calculateInvoice();
    void printInvoiceDetails();

    /*  -----   Public Getter & Setter Functions -----     */
    double getTotalPrice();
    double getSubtotalPrice();
    double getTaxRate();
    double getTaxAmt();

private:

    /*  -----    Private Data members  -----     */
    double totalPrice;
    double subtotalPrice;
    double taxRate;
    double taxAmt;
    Order order;

    /*  -----   Private Getter & Setter Functions -----     */
    void setTaxRate(double taxRateToSet);
    void setTaxAmt(double amtToSet);
    void setTotalPrice(double priceToSet);
    void setSubtotalPrice(double priceToSet);

}; //end class definition

#endif //PIZZASHOPAPP_INVOICE_H
