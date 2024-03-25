#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

// Inventory System
class Inventory {
private:
    std::vector<Item*> items; // Use pointers for polymorphic behavior

public:
    void addItem(Item* item);
    void useItem(Item* item);
    void listItems();
    Item* findItem(const std::string& name);
};

#endif //INVENTORY_H
