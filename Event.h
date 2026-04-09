// Event.h
#ifndef EVENT_H
#define EVENT_H

#include "Player.h"
#include <string>

class BaseEvent {
public:
    virtual ~BaseEvent() {}
    virtual void trigger(Player& p) = 0;
    virtual std::string getLog() = 0;
};

// Example of a specific event type
class HealthEvent : public BaseEvent {
    int amount;
public:
    HealthEvent(int a) : amount(a) {}
    void trigger(Player& p) override { p.adjustHealth(amount); }
    std::string getLog() override { 
        return (amount < 0) ? "You took damage!" : "You feel refreshed!"; 
    }
};
#endif