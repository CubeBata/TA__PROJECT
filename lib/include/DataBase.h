#pragma once 
#include <Client.h>
class Client;
class DataBase{
    std::map<size_t, Client *> clients;
public:
    DataBase();
    std::map<size_t, Client*> getAllClient();
    void insertANewClient(Client& cl);
    void showAll();
};

extern DataBase db;