#ifndef PERSON_HPP
#define PERSON_HPP
#include <bits/stdc++.h>

class Person{
    public:
        std::string name, tel;
};

class Client : public Person{
    public:
        Client(std::string n, std::string t);
};

class Functionary : public Person{
    public:
        std::pair<std::string, std::string> user_pass;
        Functionary(std::string n, std::string u, std::string p, std::string t);
};

#endif
