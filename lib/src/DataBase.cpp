#include <DataBase.h>
DataBase db;
DataBase::DataBase() {
    this->clients[0] = new Client("ADMIN", 0, "");
}

std::map<size_t, Client *> DataBase::getAllClient() {
    return this->clients;
}

void DataBase::insertANewClient(Client &cl)
{
    this->clients[cl.getID()] =  &cl;
}

void DataBase::showAll() {
    if (this->clients.empty()) {
        std::cout << "{}\n";
        return;
    }
    std::cout << "{ ";
    size_t i = 0;
    for (const auto& [k , v] : this->clients)
    {
        i++;
        std::cout << *v;
        if (i != this->clients.size())
            std::cout << ", ";
        else
            std::cout << " }\n";
    }
}