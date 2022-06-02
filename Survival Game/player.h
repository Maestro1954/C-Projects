#ifndef PLAYER_H// *****EXAMPLE CODE*****
#define PLAYER_H

#include <iostream>

using namespace std;

const unsigned int DEFAULT_HEALTH = 3;
const unsigned int DEFAULT_HUNGER = 10;
const unsigned int DEFAULT_THIRST = 5;
const bool DEFAULT_GOLD = false;
const bool DEFAULT_POTION = false;
const bool DEFAULT_STRANGER = false;

class Player {
    public:
        Player(unsigned int health, unsigned int hunger, unsigned int thirst, unsigned int x, unsigned int y, bool hasGold, bool hasPotion, bool sawStrangeBeing) {
            this->health = health;
            this->hunger = hunger;// ...equal to => unsigned int hunger
            this->thirst = thirst;
            this->x = x;
            this->y = y;
            this->hasGold = hasGold;
            this->hasPotion = hasPotion;
            this->sawStrangeBeing = sawStrangeBeing;
        }
        
        unsigned int getX() const {
            return x;
        }
        
        unsigned int getY() const {
            return y;
        }
        
        void setX(unsigned int newX) {
            x = newX;
        }
        
        void setY(unsigned int newY){
            y = newY;
        }
        
        unsigned int getHunger() const {
            return hunger;
        }
        
        void setThirst(unsigned int t) {
            thirst = t;
        }
        
        void setHunger(unsigned int h) {
            hunger = h;
        }
        
        unsigned int getHealth() const {
            return health;
        }
        
        void setHealth(unsigned int hp) {
            health = hp;
        }
        
        bool getGold() const {
            return hasGold;
        }
        
        void setGold(bool au) {
            hasGold = au;
        }
        
        bool getPotion() const {
            return hasPotion;
        }
        
        void setPotion(bool potion) {
            hasPotion = potion;
        }
        
        void strangeBeingSeen(bool yesOrNo) {
            sawStrangeBeing = yesOrNo;
        }
        
        bool sawStranger() const {
            return sawStrangeBeing;
        }
        
        void newTurn() {
            if (hunger <= 0) {
                hunger = 0;
            }
            else {
                hunger--;
            }
            
            if (thirst <= 0) {
                thirst = 0;
            }
            else {
                thirst--;
            }
            
            if ((hunger == 0) || (thirst == 0)) {
                health--;
                if ((health == 0) && (hasPotion == true)) {
                    cout << "As the cold embrace of death creeps in from all directions, you grab the potion in your travel bag and drink it fully restoring your health." << endl;
                    health = DEFAULT_HEALTH;
                    hasPotion = DEFAULT_POTION;
                }
                
                if ((health == 0) && (hasPotion == false)) {
                    cout << "You got hurt and collapsed!" << endl;
                }
            }
        }
        
        void printStats() {
            cout << "health: " << health << endl;
            cout << "hunger: " << hunger << endl;
            cout << "thirst: " << thirst << endl;
        }
        
        bool isAlive() const {
            return health > 0;
        }
    
    private:
        unsigned int health;
        unsigned int hunger;// <-this...
        unsigned int thirst;
        unsigned int x;
        unsigned int y;
        bool hasGold;
        bool hasPotion;
        bool sawStrangeBeing;
};

#endif
