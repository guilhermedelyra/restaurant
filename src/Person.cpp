#include "Person.hpp"

Client::Client(){
    string x;
    cout << "client" << endl;
    cout << "name: ";
    cin >> x;
    getName(x);
    cout << "tel: ";
    cin >> x;
    getTel(x);
}

Functionary::Functionary(){
    string x;
    cout << endl << "functionary" << endl;
    cout << "user: ";
    cin >> x;
    getName(x);
    cout << "pass: ";
    cin >> x;
    getPass(x);
    cout << "tel: ";
    cin >> x;
    getTel(x);
}

void Person::getTel(string & tel){
    this->tel = tel;
}

void Client::getName(string & n){
    this->name = n;
}

void Functionary::getName(string & u){
    this->user = u;
}

void Functionary::getPass(string & p){
    this->pass = p;
}
