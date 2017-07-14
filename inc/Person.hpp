#ifndef PERSON_HPP
#define PERSON_HPP
#include "Order.hpp"

class Person{
    public:
        string name, tel;
        virtual void getName(string & name) = 0;
        void getTel(string & tel);

};

class Client : public Person{
    public:
        Client();
        void getName(string & n);
};

class Functionary : public Person{
    public:
        pair<string, string> employee;
        // user, password
        Functionary();
        void getUP(string & u, string & p);
};

#endif
