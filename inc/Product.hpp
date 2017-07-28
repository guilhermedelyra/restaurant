#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <bits/stdc++.h>

class Product {
    public:
        std::string name;
        float price;
        int min_amount;
        Product(std::string n, float p, int m);
        bool operator<(const Product& rhs) const {
    		return name < rhs.name;
    	}
};

#endif
