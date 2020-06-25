/* main.cpp
 * Miriam Farrington
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project Submission: Pizza Shop App
 * 3/15/2020
 *
 * This program implements a basic online ordering system for a small Pizza Shop.
 * The app allows the user to select items from a menu, create an order, view the order and checkout
 *
*/


#include <iostream>
#include <zconf.h>
#include "Menu.h"
#include "Order.h"
#include "Invoice.h"
#include "Helper.h"

using namespace special_functions;
using std::cout;
using std::cin;
using std::endl;



int main() {
    sleep(1);

    printBanner();

    //variable to store the customer's selection
    int custResponse = 0;

    // --- Object Initialization --- //

    /*
     * Not all objects are created here, we try to do lazy initialization only when the object is needed
     */

    // Create and the customer Menu object
    Menu shopMenu;

    //create a new Customer Order object - currently the shop supports only 1 order per customer
    Order customerOrder;

    //Print initial welcome message to the customer
    cout << "Welcome to the Online Pizza Shop! " << endl;

    while (custResponse >= 0) {

        sleep(1);
        lineBreak(1);
        cout << "\x1b[32m ----- MAIN MENU -----\x1b[0m " <<endl;
        cout << "\x1b[32m 1) View Food & Beverage Menu \x1b[0m" << endl;
        cout << "\x1b[32m 2) Order Items \x1b[0m" << endl;
        cout << "\x1b[32m 3) View Cart \x1b[0m" << endl;
        cout << "\x1b[32m 4) Checkout \x1b[0m" << endl;
        lineBreak(2);

        cout << "\x1b[31mTo get started, select an option above or -1 to Exit : \x1b[0m ";
        cin >> custResponse; //read in the user's choice

        /*  -----    Start Input Validations -----     */
        validateCin(custResponse); //first check the user has actually entered an integer

        while (custResponse > 4 ||
               custResponse < -1) //Check a valid value is entered, otherwise prompt the user to re-enter
        {
            reset(custResponse); //reset & re-enter the value
        }


        if (custResponse == 1) { // 'View Menu' Selection
            lineBreak(1);
            cout << "\x1b[32m ----- Full Food & Beverage Menu -----\x1b[0m " << endl;
            shopMenu.printMenu();

            //Call redirect to the main menu
            menuRedirect(custResponse,1);
        }

        if (custResponse == 2) { // 'Order Items' Selection

            int orderTypeSelection = 0; //store the customer's response

            //Prompt the customer to enter the type of order they want
            sleep(1);
            lineBreak(1);
            cout << "Select your order type:  1) DINE-IN  2) TAKE-OUT  3) DELIVERY: ";
            cin >> orderTypeSelection;
            validateCin(orderTypeSelection); //check the new entered value is an integer

            while (orderTypeSelection < 0 || orderTypeSelection > 4) {
                reset(orderTypeSelection); //reset & re-enter the value
            }

            //set the customer's order type choice once it is validated
            customerOrder.setOrderType(static_cast<Order::orderTypes>(orderTypeSelection));

            //call the overloaded print function to print out the correct menu
            shopMenu.printMenu(orderTypeSelection);

            orderTypeSelection = 0; //reset the order type variable

            while (orderTypeSelection >= 0) { //While the customer has chosen to continue adding items to order...

                cout << "\x1b[31mSelect a Menu Item to add to your order: \x1b[0m";
                cin >> orderTypeSelection;
                validateCin(orderTypeSelection);

                //ensure the customer cannot order items which are not listed in the menu
                while (orderTypeSelection == 0 || orderTypeSelection > shopMenu.getMenuItems().size()) {
                    reset(orderTypeSelection); //reset & re-enter the value
                }

                int quantitySelect = 0;
                cout << "\x1b[31mEnter quantity (1-10): \x1b[0m";
                cin >> quantitySelect;
                validateCin(quantitySelect);

                while (quantitySelect <= 0 || quantitySelect > 10) {
                    reset(quantitySelect); //reset & re-enter the value
                }

                //Next, retrieve the menu item that corresponds to the customer's choice (offset index -1)
                Item* selection = shopMenu.getMenuItem(orderTypeSelection-1);

                //Update the item's quantity field
                selection->setItemQuantity(quantitySelect);

                //Add the customer's selected item to the customer's order
                customerOrder.addOrderItem(selection);

                //Call order redirect at the end
                menuRedirect(orderTypeSelection, 2);
            }

            cout << "Finished Adding items to cart." << endl;
            lineBreak(1);
            int paymentInp = 0; //customer payment selection

            //Prompt the user to select a payment method to apply to the order
            cout << "\x1b[31mSelect a payment method for your order 1) CASH 2) CARD: \x1b[0m";
            cin >> paymentInp;


            /*  -----    Start Payment Validations -----     */
            //todo: Add more detailed payment validation logic here
            validateCin(paymentInp);
            while (paymentInp < 1 || paymentInp > 2){
                reset(paymentInp); //reset the value while invalid
            }
            /*  -----    End Payment Validations -----     */

            //add the customer's Payment to the order
            if (paymentInp == 1) {
                //for now we are defaulting all orders to USD, but can expand to allow other currencies here
                customerOrder.addPaymentTypeToOrder(paymentInp, true,1);
            }
            if (paymentInp == 2){

                int cardType;
                cout << "Select 1) CREDIT or 2) DEBIT: ";
                cin >> cardType;
                validateCin(cardType);

                while (cardType < 1 || cardType > 2){
                    reset(cardType);
                }
                //Call function with customer's input selection
                customerOrder.addPaymentTypeToOrder(paymentInp, true, cardType);
            }

            // let the customer know the order is complete and to view the cart contents from the main menu.
            lineBreak(1);
            cout << "Order Complete. View your Cart or Checkout from the Main Menu" << endl;
            lineBreak(1);
            sleep(1);
        }

        if (custResponse == 3) { // ' View Cart' Selection

            if (!customerOrder.getOrderItems().empty()) {
                //show the order details
                customerOrder.printOrderDetails();

                //prompt redirect to the main menu
                menuRedirect(custResponse,3);
            } else {
                lineBreak(1);
                cout << "Cart is Empty. Please place an order from the Main Menu first." << endl;
                lineBreak(1);
            }
        }

        if (custResponse == 4) { // 'Checkout' Selection
            //before creating an invoice, first  check if the customer has items added to the order
            if (!customerOrder.getOrderItems().empty()) {
                //create the Invoice object
                Invoice customerInvoice(customerOrder);


                //calculate the Invoice totals
                customerInvoice.calculateInvoice();

                //print out the total invoice
                customerInvoice.printInvoiceDetails();

                //Place order
                customerOrder.placeOrder();

                //prompt redirect to the main menu
                menuRedirect(custResponse,1);

            } else {
                lineBreak(1);
                cout << "Order is Empty. Please place an Order from the Main Menu first." << endl;
                lineBreak(1);

            }

        }

    } cout << "Exiting Program." ;

}