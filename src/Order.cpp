#include "Order.hpp"

Order::Order(float d, float t, string o, bool x){
    this->daily_balance = d;
    this->totalvalue = t;
    this->observation = o;
    this->ok = x;
}
