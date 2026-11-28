#include <Conference.h>
Conference::Conference(size_t cost) : cost(cost)
{
    this->competitors[0] = new User("ADMIN", 0, "");
}

std::map<size_t, User *> Conference::getAllUser() {
    return this->competitors;
}

void Conference::insertANewUser(User &u)
{
    this->competitors[u.getID()] =  &u;
}

void Conference::showAll() {
    if (this->competitors.empty()) {
        std::cout << "{}\n";
        return;
    }
    std::cout << "{ ";
    size_t i = 0;
    for (const auto& [k , v] : this->competitors)
    {
        i++;
        std::cout << *v;
        if (i != this->competitors.size())
            std::cout << ", ";
        else
            std::cout << " }\n";
    }
}

void Conference::to_register(User& u)
{
    if (this->paying(u))
        this->insertANewUser(u);
}

size_t Conference::getCost() {
    return this->cost;
}

void Conference::setCost(size_t cost) {
    this->cost = cost;
}

bool Conference::paying(User &u, bool message)
{
    return u.pay(this->cost, message);
}