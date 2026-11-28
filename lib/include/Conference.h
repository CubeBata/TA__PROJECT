#pragma once 
#include <User.h>
class Conference{
    std::map<size_t, User *> competitors;
    size_t cost;
    bool paying(User &u, bool message = false); //
public:
    Conference(size_t cost = 0);
    void setCost(size_t cost);
    size_t getCost();
    std::map<size_t, User*> getAllUser();
    void insertANewUser(User& u);
    void showAll();
    void to_register(User& u); // 
};
