#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

class Player {
private:
    int health, hunger, sanity, luck;
    std::vector<Item> inventory;

public:
    Player() : health(100), hunger(100), sanity(100), luck(10) {}

    void adjustHealth(int amt) { health += amt; if(health > 100) health = 100; }
    void adjustHunger(int amt) { hunger += amt; if(hunger > 100) hunger = 100; }
    void adjustSanity(int amt) { sanity += amt; if(sanity > 100) sanity = 100; }
    void addLuck(int amt) { luck += amt; }
    void addItem(Item item) { inventory.push_back(item); }

    int getHealth() const { return health; }
    int getHunger() const { return hunger; }
    int getSanity() const { return sanity; }
    int getLuck() const { return luck; }
    int getInvSize() const { return (int)inventory.size(); }
    bool isAlive() const { return health > 0; }

    // This triggers when moving to a new node
    void tickSurvival() {
        hunger -= 5;
        sanity -= 3;
        if (hunger <= 0 || sanity <= 0) {
            std::cout << ">> You are suffering from starvation or madness! -10 HP." << std::endl;
            health -= 10;
        }
    }

    void displayStatus() const {
        std::cout << "\n====================================================" << std::endl;
        std::cout << " STATUS | HP: " << health << " | Hunger: " << hunger 
                  << " | Sanity: " << sanity << " | Luck: " << luck << std::endl;
        std::cout << " Inventory: ";
        if(inventory.empty()) std::cout << "Empty";
        for(auto& i : inventory) std::cout << "[" << i.name << "] ";
        std::cout << "\n====================================================" << std::endl;
    }
};

#endif