#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemType { RESOURCE, WEAPON, UTILITY, TRASH };

class Item {
public:
    std::string name;
    ItemType type;
    int power; 

    Item(std::string n = "None", ItemType t = ItemType::TRASH, int p = 0) 
        : name(n), type(t), power(p) {}

    std::string getTypeName() const {
        switch(type) {
            case ItemType::RESOURCE: return "Resource";
            case ItemType::WEAPON:   return "Weapon";
            case ItemType::UTILITY:  return "Utility";
            default:                 return "Trash";
        }
    }
};

#endif