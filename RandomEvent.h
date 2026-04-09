#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <iostream>
#include <cstdlib>
#include "Player.h"

class RandomEvent {
public:
    void trigger(Player& p) {
        int roll = rand() % 100;
        if (roll < 20) {
            std::cout << ">> [EVENT] You feel a cold shiver... -10 Sanity." << std::endl;
            p.adjustSanity(-10);
        } else if (roll > 80) {
            std::cout << ">> [EVENT] You find some moldy bread! +10 Hunger." << std::endl;
            p.adjustHunger(10);
        } else if (roll > 45 && roll < 55) {
            std::cout << ">> [EVENT] A trap triggers! -15 HP." << std::endl;
            p.adjustHealth(-15);
        }
    }
};

#endif