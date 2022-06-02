#include <iostream>
#include "character.h"

character::character(string nme, int off, int def, int hp, int spd, int pp, bool shield, bool stat) { // Adriel Campos
        name = nme;
        offense = off;
        defense = def;
        health = hp;
        speed = spd;
        psyPoints = pp;
        psyShield = shield;
        status = stat;
}

bool character::isAlive() const {
    return health > 0;  //This is how we know if they are alive
}

int character::getSpeed() const {
    return speed;
}

int character::getOffense() const {
    return offense;
}

int character::getDefense() const {
    return defense;
}

int character::getHealth() const {
    return health;
}

int character::getPsyPoints() const {
    return psyPoints;
}

string character::getName() const {
    return name;
}

bool character::getShield() const {
    return psyShield;
}

bool character::hasStat() const {
    return status;
}

int character::damageCalc(int attackerOff, int targetDef, bool targetHasShield) { //Original damage formula: damage = ((attack_level * offense) - defense) +/- (25% of damage)
    int damage = 0;
    
    if (targetHasShield == true) {
        damage = ((2 * attackerOff) - targetDef) / 2;
    }
    else {
        damage = (2 * attackerOff) - targetDef;
    }
    
    if (damage < 0) { //Might not be necessary
        damage = 0;
    }
    
    health = health - damage;
    
    if (health < 0) { //Might not be necessary
        health = 0;
    }
    
    return damage;
}

void character::setPP(int ppCost) {
    psyPoints = psyPoints - ppCost;
    
    if (psyPoints < 0) {
        psyPoints = 0;
    }
}

void character::psionics(int baseHp) {
    if (health > (baseHp - 20)) {
        health = baseHp;
        cout << "> " << name << " used PSI Healing. ";
        cout << name << "'s HP was maxed out!" << endl;
    }
    else {
        health = health + 20;
        cout << "> " << name << " used PSI Healing and recovered 20 HP." << endl;
    }
}

void character::psychoKinesis() {
    health = health - 15;
    
    if (health < 0) { //Might not be necessary
        health = 0;
    }
    else {
        cout << "  The " << name << " took 15 HP of damage!" << endl;
    }
}

void character::setShield(bool shieldStatus) {
    psyShield = shieldStatus;
}

void character::setStatus(bool statCondition) {
    status = statCondition;
}

void character::setHP(int damage) {
    health = health - damage;
    
    if (health < 0) {
        health = 0;
    }
}
