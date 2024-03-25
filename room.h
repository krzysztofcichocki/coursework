#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <vector>
#include "item.h"

class Room {
private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;

public:
    Room(const std::string& description);
    std::string GetDescription();
    void AddItem(const Item& item);
    std::vector<Item>& GetItems();
    void RemoveItem(const Item& item);
    void AddExit(const std::string& direction, Room* room);
    Room* GetExit(const std::string& direction);
    std::map<std::string, Room*> GetExits();
    Item* FindItem(const std::string & item);
};

#endif //ROOM_H
