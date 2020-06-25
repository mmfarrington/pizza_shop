cmake_minimum_required(VERSION 3.15)
project(PizzaShopApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(PizzaShopApp main.cpp Menu.cpp Menu.h Order.cpp Order.h Invoice.cpp Invoice.h Payment.h Payment.cpp Item.cpp Item.h FoodItem.cpp FoodItem.h DrinkItem.cpp DrinkItem.h Helper.cpp Helper.h CashPayment.cpp CashPayment.h CardPayment.cpp CardPayment.h)