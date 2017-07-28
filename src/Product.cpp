#include "Product.hpp"

Product::Product(std::string n, float p, int m){
    this->name = n;
    this->price = p;
    this->min_amount = m;
}
