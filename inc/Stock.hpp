#ifndef STOCK_HPP
#define STOCK_HPP

#include "Product.hpp"

class Stock {
    public:
        int id, quantity, min_amount;
        Stock(int id, int quantity, int min_amount);
};

#endif
