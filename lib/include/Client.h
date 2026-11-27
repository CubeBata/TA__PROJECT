#pragma once
#include <Libraries.h>
#include <DataBase.h>

class Client
{
    size_t id;
    str name;
    size_t age;
    str contact;

public:
    Client(
        const str &name, 
        size_t age, 
        const str& contact
    );
    size_t getID();
    str getName();
    size_t getAGE();
    bool operator<(const Client& cl);
    bool operator>(const Client& cl);
    bool operator<=(const Client& cl);
    bool operator>=(const Client& cl);
    bool operator==(const Client& cl);
    bool operator!=(const Client &cl);
    friend std::ostream &operator<<(std::ostream &os, const Client &cl);
};

std::ostream &operator<<(std::ostream &os, const Client &cl);