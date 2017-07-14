#include "Person.hpp"

Client::Client(string n, string t){
    this->name = n;
    this->tel = t;
}

Functionary::Functionary(string n, string u, string p, string t){
    this->name = n;
    this->employee = make_pair(u, p);
    this->tel = t;
}
