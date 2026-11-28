#pragma once
#include <Libraries.h>

class User
{
    size_t id;
    str name;
    size_t age;
    str contact;
    size_t balance;

public:
    User(
        const str &name, 
        size_t age, 
        const str &contact, 
        size_t balance = 0
    )
        : name(name), age(age), contact(contact), balance(balance) {}
    size_t getBalance();
    bool pay(size_t cost, bool message = false);
    void setBalance(size_t b);
    size_t getID();
    str getName();
    size_t getAGE();
    bool operator<(const User& u);
    bool operator>(const User& u);
    bool operator<=(const User& u);
    bool operator>=(const User& u);
    bool operator==(const User& u);
    bool operator!=(const User &u);
    friend std::ostream &operator<<(std::ostream &os, const User &u);
};

std::ostream &operator<<(std::ostream &os, const User &u);