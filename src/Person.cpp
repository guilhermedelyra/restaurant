#include "Person.hpp"

Client::Client(std::string n, std::string t){
    this->name = n;
    this->tel = t;
}

Functionary::Functionary(std::string n, std::string u, std::string p, std::string t){
    this->name = n;
    this->user_pass = make_pair(u, p);
    this->tel = t;
}
