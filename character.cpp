#include <string>
#include "character.h"

Character::Character(const std::string& name, int health) {
    this->name = name;
    this->health = health;
}

void Character::TakeDamage(int damage) {
    health -= damage;
}
