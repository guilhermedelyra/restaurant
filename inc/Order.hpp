#ifndef ORDER_HPP
#define ORDER_HPP
#include "Product.hpp"
#include "Person.hpp"

class Order {
    public:
        float totalvalue;
        string observation;
        bool ok = false;
        vector<Product> products_ordered;
        vector<int> qtd_ordered;
        Client client;
        Order(){};
};

#endif
