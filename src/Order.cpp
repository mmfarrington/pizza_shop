/* Order.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 * This program contains the implementation of the class methods defined in the Order.h header file
*/

#include "Order.h"
#include "Helper.h"
#include "CashPayment.h"
#include "CardPayment.h"
#include "FoodItem.h"

#include <iostream>
#include <zconf.h>

using namespace special_functions;
using std::cout;
using std::cin;
using std::endl;

/*  -----   Public Class Functions -----     */
void Order::printOrderDetails(){

    lineBreak(1);
    cout << "Generating Order Summary..." << endl;
    lineBreak(1);
    sleep(1);

    int counter = 1;
    lineBreak(1);
    cout << "\x1b[32m---------- Order Summary ----------\x1b[0m" << endl;
    for (Item* item: orderItems){
        cout << "Item " << counter
        << ": " << item->getItemName() << endl;
        cout << "  Price(ea): " << item->getItemPrice() << endl;
        cout << "  Quantity: " << item -> getItemQuantity() << endl;
        cout << "  Total Price: " << (item->getItemPrice() * item -> getItemQuantity()) << endl;
        cout << "\x1b[32m----------------------------------\x1b[0m" << endl;
        counter ++;
    }

    lineBreak(1);
}

void Order::addOrderItem(Item* itemToAdd){



    //add correct derived class type depending on menu selection
    orderItems.push_back(new FoodItem(itemToAdd->getItemName(),itemToAdd->getItemPrice(),itemToAdd->getItemQuantity(),
            false, false));



    lineBreak(1);
    cout << itemToAdd->getItemQuantity() << " " << itemToAdd->getItemName() << " added to order" << endl;
    lineBreak(1);
}

void Order::addPaymentTypeToOrder(int paymentType, bool validated, int cardCashType){

    //ToDo - Add a loop to allow for inputting multiple payment methods for a single order.
    // Default - only 1 payment method allowed per order

    //start adding pointers to derived class objects into the vector depending on the payment type entered
    if (validated){ //proceed if payment is validated
        if (paymentType == 1) { //CASH payment
            paymentTypes.push_back(new CashPayment(paymentType,validated,cardCashType));
            lineBreak(1);
        }
        if (paymentType == 2){ //CARD PAYMENT
            paymentTypes.push_back(new CardPayment(paymentType,validated,cardCashType));
            lineBreak(1);
        }

        //Todo: Add more derived class object pointers to the payment vector here!!

        //Read from the base class vector and call the derived class's implemented virtual function
        for (int i = 0; i < paymentTypes.size(); ++i)
        {
            paymentTypes[i]->getPaymentDetails();//Polymorphic call from base class pointer to derived class functions!!
            cout << " added to Order ----- " << endl;
        }
    } else {
        cout << "Payment type not validated. Please re-validate before proceeding." << endl;
    }
}


void Order::placeOrder(){

    lineBreak(1);
    cout << "\x1b[32mPlacing Order ...\x1b[0m" << endl;

    //clear the order items out now that the order is placed.
    orderItems.clear();

    sleep(2);

    cout << "\x1b[32mOrder Placed.\x1b[0m" << endl;

}

/*  -----   Public Getter & Setter Functions -----     */
string Order::getOrderTypeName(orderTypes type){
    if (type == DINE)
        return "Dine-In";
    if (type == TAKEOUT)
        return "Carry-out";
    if (type == DELIVERY)
        return "Delivery";
    // Just in case we add a new item in the future and forget to update this function
    return "Unknown";
}
vector <Item*>  Order::getOrderItems(){
    return orderItems;
}

Item*  Order::getOrderItem (int itemIndex){
    return orderItems[itemIndex];
}

int Order::getOrderType() {

    if (orderType == DEFAULT ||
        orderType == DINE ||
        orderType == TAKEOUT ||
        orderType == DELIVERY){
        return orderType;
    }

    return UNKNOWN; //unknown order type
}

void Order::setOrderType(int typeInp){
    orderType = typeInp;
}

vector <Payment*> Order::getPayments(){
    return paymentTypes;
}

Payment* Order::getPayment(int paymentIndex){
    return paymentTypes[paymentIndex];
}