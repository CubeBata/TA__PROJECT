#include <Client.h>

Client::Client(const str &name, size_t age, const str &contact) 
     : name(name), age(age), contact(contact)
{
    this->id = db.getAllClient().empty() ? 0 : random();
    db.insertANewClient(*this);
}

size_t Client::getID()
{
    return this->id;
}

str Client::getName() {
    return this->name;
}

size_t Client::getAGE()
{
    return this->age;
}

bool Client::operator<(const Client &cl)
{
    return this->id < cl.id;
}

bool Client::operator>(const Client &cl)
{
    return this->id > cl.id;
}

bool Client::operator<=(const Client &cl)
{
    return this->id <= cl.id;
}

bool Client::operator>=(const Client &cl)
{
    return this->id >= cl.id;
}

bool Client::operator==(const Client &cl)
{
    return this->id == cl.id;
}

bool Client::operator!=(const Client &cl)
{
    return this->id != cl.id;
}

std::ostream &operator<<(std::ostream &os, const Client &cl)
{
    os << "{ ID: "<< cl.id << ", Name: " << cl.name <<
    ", Age: " << cl.age << ", Contact: " << cl.contact << " }";
    return os;
}