#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <bits/stdc++.h>
using namespace std;

class Product {
    public:
        string name;
        float price;
        int min_amount;
        Product(string n, float p, int m);
        bool operator<(const Product& rhs) const {
    		return name < rhs.name;
    	}
};

#endif
