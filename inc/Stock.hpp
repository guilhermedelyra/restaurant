#ifndef STOCK_HPP
#define STOCK_HPP

#include "Product.hpp"

class Stock {
    public:
        std::map<Product, int> quantity;
        Stock(Product p, int c);
};

#endif
