#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include "LinkedList.h"
#include "Player.h"
#include "RandomEvent.h"

using namespace std;

int main() {
    srand(time(0));
    LinkedList castle;
    Player player;
    RandomEvent events;

    // Loading from CSV (Ensure format: Name,Description,Action1;Action2,ItemName)
    ifstream file("rooms.csv");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string name, desc, acts, itemName;
            getline(ss, name, ',');
            getline(ss, desc, ',');
            getline(ss, acts, ',');
            getline(ss, itemName);
            
            stringstream as(acts);
            string a; vector<string> v;
            while (getline(as, a, ';')) v.push_back(a);

            castle.addRoom(Room(name, desc, v, Item(itemName, ItemType::RESOURCE)));
        }
        file.close();
    }

    auto current = castle.getHead();
    cout << "Welcome to the Gauntlet. Survive as long as you can.\n";

    while (current && player.isAlive()) {
        player.displayStatus();
        cout << "\nLOCATION: " << current->room.getName() << endl;
        cout << current->room.getDescription() << endl;

        auto actions = current->room.getActions();
        int i = 1;
        for (const auto& act : actions) cout << i++ << ". " << act << endl;
        cout << i << ". Move to Next Room" << endl;

        int choice;
        cout << "\nWhat will you do? ";
        cin >> choice;

        if (choice > 0 && choice <= (int)actions.size()) {
            // Player chose a room action
            events.trigger(player);
            if (!current->room.isSearched()) {
                Item found = current->room.takeItem();
                if (found.name != "None") {
                    cout << ">> Picked up: " << found.name << endl;
                    player.addItem(found);
                }
            } else {
                cout << ">> Nothing else to find here." << endl;
            }
        } else if (choice == (int)actions.size() + 1) {
            // Player leaves the room
            player.tickSurvival();
            current = current->next;
            cout << ">> You venture deeper into the dark..." << endl;
        }

        if (!player.isAlive()) {
            cout << "\n*** YOU PERISHED ***\nRooms Conquered: " << player.getInvSize() << endl;
            break;
        }
    }

    if (player.isAlive()) cout << "You reached the end of the gauntlet!" << endl;

    return 0;
}