#ifndef INC_PERSON_H
#define INC_PERSON_H
#include "OrderedProduct.hpp"

class Person{
    protected:
        int tel;
    public:
        virtual void getName() = 0;
        void getTel();
        Person();
        ~Person();
};

class Client : public Person{

}

class Functionary : public Person{
    protected
}
