#include "command_interpreter.h"

#include <iostream>
#include <sstream>
#include "player.h"
#include "inventory.h"

void CommandInterpreter::interpretCommand(const std::string& command) {
    // Split the command into words and identify the action and optional parameters
    // Tip: you can use std::istringstream for splitting the string
    std::istringstream iss(command);
    std::string word;

    // Loop through the words in the command
    while (iss >> word) {
        // List of available commands
        if (word == "help") {
            std::cout << "Available commands: " << std::endl;
            std::cout << "help" << std::endl;
            std::cout << "look" << std::endl;
            std::cout << "use [object]" << std::endl;
            std::cout << "take [object]" << std::endl;
            std::cout << "move {north/east/south/west}" << std::endl;
            std::cout << "inventory" << std::endl;
            std::cout << "quit" << std::endl;

        } else if (word == "look") {
            // Show player's location, items in the room, and available exits
            std::cout << "Current location: " << player_->GetLocation()->GetDescription() << std::endl;
            std::cout << "Items in the room:" << std::endl;
            for (const Item& item : player_->GetLocation()->GetItems()) {
                std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
            }
            std::cout << "Exits available: ";
            for (const auto& exit : player_->GetLocation()->GetExits()) {
                std::cout << exit.first << " ";
            }
            std::cout << std::endl;
        } else if (word == "use") {
            std::string itemName;
            iss >> itemName; // Take next word from command as the item name
            // Call the appropriate method in the player object
            player_->useItem(itemName);
        } else if (word == "take") {
            std::string itemName;
            iss >> itemName; // Take next word from command as the item name
            // Call the appropriate method in the player object
            player_->takeItem(itemName);
        } else if (word == "inventory") { // List the items in the player's inventory
            player_->listItems();
        } else if (word == "move") { // Move the player to a different room
            std::string direction;
            iss >> direction; // Take next word from command as the direction
            if (direction == "north" || direction == "south" || direction == "east" || direction == "west") {
                // Call the appropriate method in the player object
                player_->move(direction);
            } else {
                std::cout << "Invalid direction" << std::endl;
            }

        } else if (word == "quit") { // Exit the game
            std::cout << "Goodbye!" << std::endl;
            exit(0);
        }
    }
}
