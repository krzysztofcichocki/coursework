#include "inventory.h"
#include <iostream>

void Inventory::addItem(Item* item) {
    // Add item to inventory
    items.push_back(item);
}

void Inventory::useItem(Item* item) {
    // Use item
    item->Interact();
}

void Inventory::listItems() {
    // List all items in inventory
    for (Item* item : items) {
        std::cout << item->GetName() << std::endl;
    }
}

Item* Inventory::findItem(const std::string& name) {
    // Find item by name
    for (Item* item : items) { // For each item in the inventory
        if (item->GetName() == name) { // If the item name matches the input
            return item; // Return the item
        }
    }
    return nullptr;
}