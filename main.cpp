#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "area.h"
#include "character.h"
#include "player.h"
#include "room.h"
#include "item.h"
#include "command_interpreter.h"

int main() {
    // Create an instance of the Area class
    Area gameWorld;

    // Load the game map from a text file
    gameWorld.LoadMapFromFile("game_map.txt");

    // Load the items from a text file
    gameWorld.LoadItemsFromFile("items.txt");

    // Create a Player
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;
    Player player(playerName, 100);

    // Initialize the CommandInterpreter
    CommandInterpreter interpreter(&player);

    // Set the player's starting location
    Room* currentRoom = gameWorld.GetRoom("startRoom");
    player.SetLocation(currentRoom);

    // Command Interpreter loop
    std::string command;
    while (true) {
        // Player enters command
        std::cout << "> ";
        std::getline(std::cin, command);

        // Exit the loop if the command is "quit"
        if (command == "quit") {
            break;
        }

        // Interpret the command
        interpreter.interpretCommand(command);
    }
    return 0;
}