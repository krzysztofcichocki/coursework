#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <string>
#include "player.h"

// Forward declaration of the Player class
class Player;

// CommandInterpreter class definition
class CommandInterpreter {
private:
    Player* player_; // Pointer to the player object
public:
    CommandInterpreter(Player* player) : player_(player) {}
    void interpretCommand(const std::string& command);
};


#endif //COMMAND_INTERPRETER_H
