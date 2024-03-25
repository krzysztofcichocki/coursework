#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include "inventory.h"

class Player : public Character {
private:
    Room* location;
    Inventory inventory;

public:
    Player(const std::string& name, int health);
    Room* GetLocation();
    void SetLocation(Room* location);
    void move(std::string& direction);
    void takeItem(std::string& item);
    void useItem(std::string& item);
    void listItems();

};

#endif //PLAYER_H
