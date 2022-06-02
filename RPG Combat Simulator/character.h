#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std; // Adriel Campos

class character {
    public:
        character(string nme, int off, int def, int hp, int spd, int pp, bool shield, bool stat);
        bool isAlive() const; //We don't want our accessor to modify properties of our character
        int getSpeed() const; //Accessors are only retreiving information
        int getOffense() const;
        int getDefense() const;
        int getHealth() const;
        int getPsyPoints() const;
        string getName() const;
        bool getShield() const;
        bool hasStat() const;
        int damageCalc(int attackerOff, int targetDef, bool targetHasShield);
        void setPP(int ppCost);
        void psionics(int baseHp);
        void psychoKinesis();
        void setShield(bool shieldStatus);
        void setStatus(bool statCondition);
        void setHP(int damage);
    
    private:
        string name;
        int offense;
        int defense;
        int health;
        int speed;
        int psyPoints;
        bool psyShield;
        bool status;
    
};

#endif
