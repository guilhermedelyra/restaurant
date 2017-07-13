#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Order.hpp"

class Product : Order {
    public:
        string name;
        float price;
        int id, quant;
        Product(string n, float p);
};

#endif
