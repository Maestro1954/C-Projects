#include "lands.h"// *****EXAMPLE CODE*****

using namespace std;

Land* getRandomLand() {
    int selection = rand() % 7;
    
    switch (selection) {
        case 0:
            return new Lake;
            break;
        case 1:
            return new Forest;
            break;
        case 2:
            return new Cave;
            break;
        case 3:
            return new Desert;
            break;
        case 4:
            return new Boneyard;
            break;
        case 5:
            return new Town;
            break;
        case 6:
            return new AncientRuins;
            break;
        default:
            //cout << "Unexepcted value: " << selection << endl;
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription() {
    return "lake";
}

string Lake::getLongDescription() {
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p) {
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription() {
    return "forest";
}

string Forest::getLongDescription() {
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p) {
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    if (chance > 50) {
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    return description;
}

string Cave::getShortDescription() {// New code
    return "cave";
}

string Cave::getLongDescription() {
    return "You arrive at a cave whose interior is full of beautiful crystals and precious metals.";
}

string Cave::visit(Player& p) {
    int chance = rand() % 100;
    
    if ((p.getGold() == false) && (chance > 50)) {
        p.setGold(true);
        return "During your adventure in the cave you find a deposit of gold ore. You pocket some of the gold ore.";
    }
    else if (p.getGold() == true) {
        return "During your adventure in the cave you find a deposit of gold ore. Unfortunately, your pockets are full.";
    }
    else {
        return "You pass through the cave gawking at all the pretty crystals; you trip on your way out. What a doofus...";
    }
}

string Desert::getShortDescription() {// New code
    return "desert";
}

string Desert::getLongDescription() {
    return "You arrive at a scorching desert; saliva instantly evaporates from your tongue.";
}

string Desert::visit(Player& p) {
    p.setHealth(p.getHealth() - 1);
    return "The hot sun and burning desert sands gave you a sunstroke.";
}

string Boneyard::getShortDescription() {// New code
    return "boneyard";
}

string Boneyard::getLongDescription() {
    return "You arrive at a boneyard full of the rotting bones of various creatures.";
}

string Boneyard::visit(Player& p) {
    int chance = rand() % 100;
    
    if (chance > 75) {
        p.setHealth(0);
        p.strangeBeingSeen(true);
        return "During your ill advised venture through the boneyard, you encounter a mysterious apparition.\nIt speaks: \"))$!{##|{}!!*!(\"\nYou died...";
    }
    else {
        return "You pass through the boneyard stepping over various carcases. You feel a cold chill down your spine, but nothing happended";
    }
}

string Town::getShortDescription() {// New code
    return "town";
}

string Town::getLongDescription() {
    return "You arrive at a creepy looking town of suspicious individuals.";
}

string Town::visit(Player& p) {
    if (p.getGold() == true) {
        p.setHealth(DEFAULT_HEALTH);
        p.setHunger(DEFAULT_HUNGER);
        p.setThirst(DEFAULT_THIRST);
        p.setGold(DEFAULT_GOLD);
        return "You offer the gold in your pockets to the town's healer. Your health is fully restored, as well as quenching your thirst and satisfying your hunger.";
    }
    else {
        return "The town has a healer to restore your health, unfortunately you have no gold to offer in exchange for healing.";
    }
}

string AncientRuins::getShortDescription() {// New code
    return "ancient ruins";
}

string AncientRuins::getLongDescription() {
    return "You stumble upon some ancient ruins, whose exterior is covered in vines and overgrowth.";
}

string AncientRuins::visit(Player& p) {
    int chance = rand() % 100;
    
    if ((chance > 75) && (p.getPotion() == false)) {
        p.setPotion(true);
        return "While exporing the ancient ruins you find a mysterious potion, to grab it and place it in your travel bag for safe keeping.";
    }
    else {
        return "You pass through the ancient ruins captivated by the beautiful scenery.";
    }
}
