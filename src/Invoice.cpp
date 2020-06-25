/* Invoice.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the class methods defined in the Invoice.h header file
*/

#include "Invoice.h"
#include "Helper.h"
#include <iostream>
#include <zconf.h>

using namespace special_functions;
using std::cout;
using std::cin;
using std::endl;


/*  -----   Public Class Functions -----     */
void Invoice::calculateInvoice(){
    //set the tax rate - for now we will fix at % 8.875
    //Todo: add functionality to support multiple tax rates (e.g. store opens a new location)
    setTaxRate(8.875);

    //calculate the subtotal based on order items
    for (int i = 0; i < order.getOrderItems().size(); ++i) {
        double itemPrice = (order.getOrderItem(i)->getItemPrice() * order.getOrderItem(i)->getItemQuantity());
        subtotalPrice += itemPrice;
    }

    //calculate the taxes based on rate
    setTaxAmt((getTaxRate() / 100) * subtotalPrice);

    //set the total price
    setTotalPrice(subtotalPrice + taxAmt);

}
void Invoice::printInvoiceDetails(){
    int paymentType = order.getPayment(0)->getPaymentType();
    string paymentDesc = order.getPayment(0)->getPaymentTypeDesc(paymentType);

    //call the generic order print function
    order.printOrderDetails();

    lineBreak(1);
    cout << "Generating Invoice Summary..." << endl;
    lineBreak(1);


    lineBreak(1);
    sleep(1);
    cout << "\x1b[32m--------- Invoice Summary ---------\x1b[0m" << endl;
    cout << "SUBTOTAL: " << subtotalPrice << endl;
    cout << "Tax Rate: " << taxRate << endl;
    cout << "Sales Tax Amt: " << taxAmt << endl;
    cout << "\x1b[32m----------------------------------\x1b[0m" << endl;
    cout << "GRAND TOTAL: " << totalPrice << endl;
    cout << "Payment Method: " << paymentDesc << endl;
    cout << "\x1b[32m----------------------------------\x1b[0m" << endl;
    lineBreak(1);
}

/*  -----   Public Getter & Setter Functions -----     */
double Invoice::getTotalPrice(){
    return totalPrice;
}

double Invoice::getSubtotalPrice(){
    return subtotalPrice;
}

double Invoice::getTaxRate(){
    return taxRate;
}
double Invoice::getTaxAmt(){
    return taxAmt;
}

/*  -----   Private Getter & Setter Functions -----     */
void Invoice::setTaxRate(double taxRateToSet){
    taxRate = taxRateToSet;
}

void Invoice::setTaxAmt(double amtToSet){
    taxAmt = amtToSet;
}

void Invoice::setTotalPrice(double priceToSet){
    totalPrice = priceToSet;

}
void Invoice::setSubtotalPrice(double priceToSet){
    subtotalPrice = priceToSet;
}