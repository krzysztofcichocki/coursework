#include <iostream>
#include "player.h"

Player::Player(const std::string& name, int health) : Character(name, health) {
    // Initialize the player
    location = nullptr;
}

void Player::SetLocation(Room* location) {
    this->location = location;
}

Room* Player::GetLocation() {
    return location;
}

void Player::move(std::string& direction) {
    // Check if the player can move in the given direction
    if (Room* nextRoom = this->GetLocation()->GetExit(direction); nextRoom != nullptr) {
        this->SetLocation(nextRoom); // Move the player to the next room
        std::cout << "You are now in " << nextRoom->GetDescription() << std::endl;
    } else {
        std::cout << "There is no exit in that direction" << std::endl;
    }
}

void Player::takeItem(std::string& item) {
    // Check if the item is in the current room
    if (Item* foundItem = this->GetLocation()->FindItem(item); foundItem != nullptr) {
        inventory.addItem(foundItem); // Add the item to the player's inventory
        this->GetLocation()->RemoveItem(*foundItem); // Remove the item from the room
        std::cout << "You picked up " << foundItem->GetName() << std::endl;
    } else {
        std::cout << "Item not found in this room" << std::endl;
    }
}

void Player::useItem(std::string& item) {
    // Check if the item is in the player's inventory
    if (Item* foundItem = inventory.findItem(item); foundItem != nullptr) {
        inventory.useItem(foundItem); // Use the item
    } else {
        std::cout << "Item not found in inventory" << std::endl;
    }
}

void Player::listItems() {
    inventory.listItems(); // List all items in the player's inventory
}