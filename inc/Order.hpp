#ifndef ORDER_HPP
#define ORDER_HPP
#include "Product.hpp"
#include "Person.hpp"

class Order {
    public:
        float totalvalue;
        std::string observation;
        bool ok = false;
        std::vector<Product> products_ordered;
        std::vector<int> qtd_ordered;
        Client *client;
        Order();
};

#endif
