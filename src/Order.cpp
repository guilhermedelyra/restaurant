#include "Order.hpp"

Order::Order(float t, string o, bool x){
    this->totalvalue = t;
    this->observation = o;
    this->ok = x;
}
