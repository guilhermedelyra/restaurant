#ifndef PERSON_HPP
#define PERSON_HPP
#include "Order.hpp"

class Person{
    public:
        string name, tel;
};

class Client : public Person{
    public:
        Client(string n, string t);
};

class Functionary : public Person{
    public:
        pair<string, string> employee;
        Functionary(string n, string u, string p, string t);
};

#endif
