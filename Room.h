#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"

class Room {
private:
    std::string name;
    std::string description;
    std::vector<std::string> actions;
    Item roomItem;
    bool searched;

public:
    Room(std::string n, std::string d, std::vector<std::string> a, Item i)
        : name(n), description(d), actions(a), roomItem(i), searched(false) {}

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::vector<std::string> getActions() const { return actions; }
    
    bool isSearched() const { return searched; }
    Item takeItem() { 
        Item temp = roomItem; 
        roomItem = Item("None"); 
        searched = true; 
        return temp; 
    }
};

#endif