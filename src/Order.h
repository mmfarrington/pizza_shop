/* Order.h
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program defines the public and private interfaces for the Order Class
*/


#ifndef PIZZASHOPAPP_ORDER_H
#define PIZZASHOPAPP_ORDER_H


#include <string>
#include <vector>
#include "Item.h"
#include "Payment.h"
#include "Menu.h"

using std::string;
using std::vector;


class Order { //Start class definition

public:

    /*  -----   Enumerated Order Types Defined -----     */
    enum orderTypes
    {
        UNKNOWN = -1,
        DEFAULT = 0,
        DINE = 1,
        TAKEOUT = 2,
        DELIVERY = 3
    };

    /*  -----   Public class constructor  -----     */
    Order ()  {   // Start Constructor body

        //initialize private variables to 0
        setOrderType(DEFAULT);

    } //End Constructor body

    /*  -----   Public Class Functions -----     */

    /* print out the existing order details */
    void printOrderDetails();

    /* Add an order item to the vector of order items  */
    void addOrderItem(Item* itemToAdd);

    /* add the selected Payment type to the customer's order */
    void addPaymentTypeToOrder(int paymentType, bool validated, int cardCashType);

    /* Place customer's order and clear out the order items */
    void placeOrder();


    /*  -----   Public Getter & Setter Functions -----     */
    string getOrderTypeName(orderTypes type);
    vector <Item*> getOrderItems();
    vector <Payment*> getPayments();
    Item* getOrderItem (int itemIndex);
    Payment* getPayment(int paymentIndex);
    int getOrderType();
    void setOrderType(int typeInp);

private:

    /*  -----    Private Data members  -----     */
    vector <Payment*> paymentTypes;
    vector <Item*> orderItems;
    int orderType;


}; //end class definition

#endif //PIZZASHOPAPP_ORDER_H
