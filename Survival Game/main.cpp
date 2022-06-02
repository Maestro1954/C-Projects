#include <iostream>// *****EXAMPLE CODE*****
#include <algorithm>
#include "lands.h"
#include "player.h"

using namespace std;

void clearTerminal() {
    for (int i = 0; i < 100; i++) {
        cout << endl;
    }
}

bool getPlayerInput(int &playerChoice) {
    // 0 = North, 1 = South, 2 = East, 3 = West
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if (input == "n") {
        playerChoice = 0;
    }
    else if (input == "s") {
        playerChoice = 1;
    }
    else if (input == "e") {
        playerChoice = 2;
    }
    else if (input == "w") {
        playerChoice = 3;
    }
    else if (input == "x") {
        playerChoice = 4;
    }
    else {
        cout << "Invalid input." << endl;
        return false;
    }
    
    return true;
}


int main(){
    const unsigned int MAP_SIZE = 20;
    Player player(DEFAULT_HEALTH, DEFAULT_HUNGER, DEFAULT_THIRST, MAP_SIZE/2, MAP_SIZE/2, DEFAULT_GOLD, DEFAULT_POTION, DEFAULT_STRANGER);
    
    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {// i = x
        for (int j = 0; j < MAP_SIZE; j++) {// j = y
            map[i][j] = getRandomLand();
        }
        cout << endl;
    }
    
    cout << "You wake up in a " << map[player.getX()][player.getY()]->getShortDescription() << " with no memory of how you got there." << endl;
        
    while (player.isAlive()) {
        clearTerminal();
        player.newTurn();
        player.printStats();
        
        if (player.getHealth() != 0) {
            // Give description of surroundings
            unsigned int x = player.getX();
            unsigned int y = player.getY();
            
            cout << map[x][y]->getLongDescription() << endl;
            cout << map[x][y]->visit(player) << endl;
            
            if (player.sawStranger() != true) {
                cout << "Location: X-" << player.getX() << ", Y-" << player.getY() << endl;
                
                // TODO: Handle boundry conditions
                if (player.getY() != (MAP_SIZE - 1)) {
                    cout << "To the north you see a " << map[x][y + 1]->getShortDescription() << endl;
                }
                if (player.getY() != 0) {
                    cout << "To the south you see a " << map[x][y - 1]->getShortDescription() << endl;
                }
                if (player.getX() != (MAP_SIZE - 1)) {
                    cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl;
                }
                if (player.getX() != 0) {
                    cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl;
                }
                
                int playerChoice;
                while (!getPlayerInput(playerChoice));
                
                switch (playerChoice) {
                    case 0:
                        if (player.getY() == (MAP_SIZE - 1)) {
                            player.setY(0);
                        }
                        else {
                            player.setY(player.getY() + 1);
                        }
                        break;
                    case 1:
                        if (player.getY() == 0) {
                            player.setY(MAP_SIZE - 1);
                        }
                        else {
                            player.setY(player.getY() - 1);
                        }
                        break;
                    case 2:
                        if (player.getX() == (MAP_SIZE - 1)) {
                            player.setX(0);
                        }
                        else {
                            player.setX(player.getX() + 1);
                        }
                        break;
                    case 3:
                        if (player.getX() == 0) {
                            player.setX(MAP_SIZE - 1);
                        }
                        else {
                            player.setX(player.getX() - 1);
                        }
                        break;
                    case 4:
                        cout << "Program will close, health set to zero." << endl;
                        player.setHealth(0);
                        break;
                    default:
                        cout << "Invalid input found: " << playerChoice << endl;
                        break;
                }
            }
        }
    }
    
    return 0;
}
