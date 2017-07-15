#ifndef ORDER_HPP
#define ORDER_HPP
#include <bits/stdc++.h>
using namespace std;

class Order {
    public:
        float totalvalue;
        string observation;
        bool ok = true;
        Order(float t, string o, bool x);
};

#endif
