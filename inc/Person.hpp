#ifndef PERSON_HPP
#define PERSON_HPP
#include <bits/stdc++.h>
using namespace std;

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
        pair<string, string> user_pass;
        Functionary(string n, string u, string p, string t);
};

#endif
