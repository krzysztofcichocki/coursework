#include <iostream>
#include "item.h"

Item::Item(const std::string& name, const std::string& desc) {
    this->name = name;
    this->description = desc;
}

std::string Item::GetName() const {
    return name;
}

std::string Item::GetDescription() const {
    return description;
}

void Item::Interact() {
    std::cout << "You interacted with " << name << std::endl;
}