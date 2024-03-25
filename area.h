#ifndef AREA_H
#define AREA_H

#include <string>
#include <map>
#include "room.h"

class Area {
private:
    std::map<std::string, Room*> rooms; // Map of rooms

public:
    void AddRoom(const std::string& name, Room* room);
    Room* GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1name, const std::string& room2Name, const std::string& direction);
    void LoadMapFromFile(const std::string& filename);
    std::string GetOppositeDirection(const std::string& direction);
    void AddItemToRoom(const std::string& roomName, const Item& item);
    void LoadItemsFromFile(const std::string& filename);
};

#endif //AREA_H
