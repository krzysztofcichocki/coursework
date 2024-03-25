#include "area.h"
#include "room.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Area::AddRoom(const std::string& name, Room* room) { // Add a room to the area
    rooms[name] = room;
}

Room* Area::GetRoom(const std::string& name) { // Get a room by name
    return rooms[name];
}

void Area::ConnectRooms(const std::string& room1name, const std::string& room2Name, const std::string& direction) {
    // Add exit between two rooms in both directions
    rooms[room1name]->AddExit(direction, rooms[room2Name]);
    rooms[room2Name]->AddExit(GetOppositeDirection(direction), rooms[room1name]);
}

void Area::LoadMapFromFile(const std::string &filename) { // Load the game map from a text file
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) { // Read each line from the file
            std::string room1name;
            std::string room2name;
            std::string direction;
            std::istringstream iss(line);
            iss >> room1name >> room2name >> direction; // Extract room names and direction from the line
            // if room1 doesn't already exist, create new room.
            if (rooms.find(room1name) == rooms.end()) {
                rooms[room1name] = new Room(room1name);
            }
            // if room2 doesn't already exist, create new room.
            if (rooms.find(room2name) == rooms.end()) {
                rooms[room2name] = new Room(room2name);
            }
            ConnectRooms(room1name, room2name, direction);
        }
        inputFile.close();
    } else {
        std::cout << "Could not open file: " << filename << std::endl;
    }

}


std::string Area::GetOppositeDirection(const std::string& direction) {
    // Return the opposite direction
    if (direction == "north") {
        return "south";
    } else if (direction == "south") {
        return "north";
    } else if (direction == "east") {
        return "west";
    } else if (direction == "west") {
        return "east";
    } else {
        return "Invalid direction";
    }
}

void Area::AddItemToRoom(const std::string& roomName, const Item& item) {
    // Add an item to a room
    rooms[roomName]->AddItem(item);
}

void Area::LoadItemsFromFile(const std::string& filename) {
    // Load items from a text file
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string roomName;
            std::string itemName;
            std::string itemDescription;
            std::istringstream iss(line);
            iss >> roomName >> itemName; // Extract room name and item name from the line
            std::getline(iss, itemDescription); // Extract the rest of the line as the item description
            Item item(itemName, itemDescription); // Create an item
            AddItemToRoom(roomName, item); // Add the item to the room
        }
        inputFile.close();
    } else {
        std::cout << "Could not open file: " << filename << std::endl;
    }
}
