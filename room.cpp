#include "room.h"

Room::Room(const std::string& description) {
    this->description = description;
}

std::string Room::GetDescription() {
    return description;
}

void Room::AddItem(const Item& item) {
    items.push_back(item);
}

std::vector<Item>& Room::GetItems() {
    return items;
}

void Room::RemoveItem(const Item& item) {
    items.pop_back();
}

void Room::AddExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

std::map<std::string, Room*> Room::GetExits() {
    return exits;
}

Room* Room::GetExit(const std::string& direction) {
    return exits[direction];
}

Item* Room::FindItem(const std::string& item) {
    for (Item& i : items) { // For each item in the room
        if (i.GetName() == item) { // If the item name matches the input
            return &i; // Return the item
        }
    }
    return nullptr;
}