#include <User.h>


size_t User::getID()
{
    return this->id;
}

str User::getName() {
    return this->name;
}

size_t User::getAGE()
{
    return this->age;
}

bool User::operator<(const User &u)
{
    return this->id < u.id;
}

bool User::operator>(const User &u)
{
    return this->id > u.id;
}

bool User::operator<=(const User &u)
{
    return this->id <= u.id;
}

bool User::operator>=(const User &u)
{
    return this->id >= u.id;
}

bool User::operator==(const User &u)
{
    return this->id == u.id;
}

bool User::operator!=(const User &u)
{
    return this->id != u.id;
}

void pay(size_t cost) {
    
}

std::ostream &operator<<(std::ostream &os, const User &u)
{
    os << "{ ID: "<< u.id << ", Name: " << u.name <<
    ", Age: " << u.age << ", Contact: " << u.contact << " }";
    return os;
}

size_t User::getBalance() {
    return this->balance;
}

void User::setBalance(size_t b) {
    this->balance = b;
}

bool User::pay(size_t cost, bool message) {
    if (this->balance >= cost) {
        this->balance-=cost;
        if (message)
            std::cout << "-User \"" << this->name << "\" has expense " << cost << "$. His balance is " << this->balance << "$.\n"; 
        return true;
    }
    if (message)
        std::cout << "-User \"" << this->name << "\" have a few of balance for pay " << cost << "&\n";
    return false;
}