#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "room.h"
#include "item.h"

class Character {
private:
    std::string name;
    int health;
    std::vector<Item> inventory;

public:
    Character(const std::string& name, int health);
    void TakeDamage(int damage);
};

#endif //CHARACTER_H