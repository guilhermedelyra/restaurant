#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Order.hpp"

class Product {
    public:
        string name;
        float price;
        Product(string n, float p);
};

#endif
