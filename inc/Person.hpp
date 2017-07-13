#ifndef PERSON_HPP
#define PERSON_HPP
#include "Order.hpp"

class Person{
    public:
        string tel;
        virtual void getName(string & name) = 0;
        void getTel(string & tel);

};

class Client : public Person{
    public:
        string name;
        Client();
        void getName(string & n);
};

class Functionary : public Person{
    public:
        string user, pass;
        Functionary();
        void getName(string & u), getPass(string & p);
};

#endif
