#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "character.h"

using namespace std;    //g++ main.cpp character.cpp -o test -std=c++11
                        //to run: ./test
character fightOrCheck(character user, character cpu, int actTaken, int missRate) { //---> Player fights or checks.

    if ((actTaken == 1) && (user.hasStat() == true)) {
        if (missRate > 5) {
            cout << "> " << user.getName() << " bashed the " << cpu.getName() << " and dealt ";
            cout << cpu.damageCalc(user.getOffense(), cpu.getDefense(), cpu.getShield()) << " HP of damage!" << endl;
        }
        else {
            cout << "> " << user.getName() << " missed the " << cpu.getName() << "." << endl;
        }
    }
    else if (actTaken == 3) {
        cout << "> " << user.getName() << " checked the " << cpu.getName() << ":" << endl;
        cout << "  The " << cpu.getName() << "'s offense is " << cpu.getOffense() << " and its defense is " << cpu.getDefense() << "." << endl;
        if (cpu.getName() == "Shadowman") {
            cout << "  This enemy is a user of PSI, and can mess with your mind to disrupt your motor function." << endl;
        }
        else if (cpu.getName() == "Cyberpede") {
            cout << "  This enemy can use the strange lights on it's tail to blind you, lowering your accuracy." << endl;
        }
        else {
            cout << "  This enemy's terrible smell can make it hard to get in close and attack." << endl;
        }
    }
    else {
        cout << "> " << user.getName() << " bashed the " << cpu.getName() << " and dealt ";
        cout << cpu.damageCalc(user.getOffense(), cpu.getDefense(), cpu.getShield()) << " HP of damage!" << endl;
    }
    
    return cpu;
}

character psiShieldOrCure(character user, int ppCost, bool shieldsDown, bool usedCure) { //---> When PSI Shield/Cure was or is used
    if (usedCure == false) {
        if (shieldsDown == false) {
            user.setPP(ppCost);
            if (user.getShield() == false) {
                cout << "> " << user.getName() << " raised a psychic shield!" << endl;
                user.setShield(true);
            }
            else if (user.getShield() == true) {
                cout << "> " << user.getName() << "'s psychic shield was renewed." << endl;
            }
        }
        else {
            cout << "> " << user.getName() << "'s psychic shield wore off." << endl;
            user.setShield(false);
        }
    }
    else {
        user.setPP(ppCost);
        if (user.hasStat() == false) {
            cout << "> " << user.getName() << " used PSI Cure, but nothing happened." << endl;
        }
        else {
            cout << "> " << user.getName() << " used PSI Cure, and cured all status ailments." << endl;
            user.setStatus(false);
        }
    }
    
    return user;
}

character computerCombat(character cpu, character user, int cpuMonster, int actTaken, bool statusEffect, string thing) { //---> Computer attacks.
    int statAttkRate;

    if (cpuMonster == 1) {// How often they inflict a status condition on the player
        statAttkRate = 2;
    }
    else if (cpuMonster == 2) {
        statAttkRate = 6;
    }
    else {
        statAttkRate = 3;
    }
    
    if (actTaken > statAttkRate) {
        cout << "> The " << cpu.getName() << " attacked you and dealt " << user.damageCalc(cpu.getOffense(), user.getDefense(), user.getShield()) << " HP of damage!" << endl;
    }
    else {
        if (cpuMonster == 1) {
            if (statusEffect == true) {
                cout << "> The Cyberpede stalks its prey. " << user.getName() << " can't see very well." << endl;
            }
            else {
                cout << "> The Cyberpede flashed the lights on its tail!\n  " << user.getName() << " was blinded." << endl;
                user.setStatus(true);
            }
        }
        else if (cpuMonster == 2) {
            if ((actTaken == 6) || (actTaken == 5)) { //---> Special case of cpu using psi
                if (user.getShield() == true) {
                    cout << "> The Shadowman used PSI " << thing << "! " << user.getName() << "'s psychic shield was shattered!" << endl;
                    user.setShield(false);
                }
                else {
                    cout << "> The Shadowman used PSI " << thing << "! " << user.getName() << " took 15 HP of damage!" << endl;
                    user.setHP(15);
                }
            }
            else if (statusEffect == true) {
                cout << "> The Shadowman's influence intensifies! " << user.getName() << " is feeling strange." << endl;
            }
            else {
                cout << "> The Shadowman used PSI Mindshock!\n  " << user.getName() << " felt strange." << endl;
                user.setStatus(true);
            }
        }
        else {
            if (statusEffect == true) {
                cout << "> The smell is unbearable! " << user.getName() << " can't stop crying." << endl;
            }
            else {
                cout << "> The Nasty Slime let out a very stinky gas!\n  " << user.getName() << " could not stop crying." << endl;
                user.setStatus(true);
            }
        }
    }
    
    return user;
}

void displayInterface(character user, int baseHP, int basePP, string thing, string spaces, int menuNum) { //---> Function for displaying user interface.
    if (menuNum == 1) {
        if (user.hasStat() == true) {
            cout << "####################################" << endl;
            cout << "# (1) Fight        (3) Check       #\n" << "# (2) Psionics                     #" << endl;
            cout << "####################################\n" << "Input action: ";
        }
        else {
            cout << "************************************" << endl;
            cout << "* (1) Fight        (3) Check       *\n" << "* (2) Psionics                     *" << endl;
            cout << "************************************\n" << "Input action: ";
        }
    }
    else if (menuNum == 2) {
        if (user.hasStat() == true) {
            cout << "####################################" << endl;
            cout << "# (A) PSI " << thing << " - PP Cost: 10" << spaces << "   #\n" << "# (B) PSI Healing - PP Cost: 6     #" << endl;
            cout << "# (C) PSI Shield - PP Cost: 4      #" << endl;
            cout << "# (D) PSI Cure - PP Cost: 2        #" << endl;
            cout << "####################################\n" << "Input action: ";
        }
        else {
            cout << "************************************" << endl;
            cout << "* (A) PSI " << thing << " - PP Cost: 10" << spaces << "   *\n" << "* (B) PSI Healing - PP Cost: 6     *" << endl;
            cout << "* (C) PSI Shield - PP Cost: 4      *" << endl;
            cout << "* (D) PSI Cure - PP Cost: 2        *" << endl;
            cout << "************************************\n" << "Input action: ";
        }
    }
    else {
        cout << "Name: " << user.getName() << "  HP: " << user.getHealth() << "/" << baseHP << "  ";
        cout << "PP: " << user.getPsyPoints() << "/" << basePP << endl;
    }
}

void cpuDialogue(string name, int cpuMonster, int dialogue) {// Unique dialogue for each enemy
    if (cpuMonster == 1) {
        if (dialogue == 1) {
            cout << "> The Cyberpede brandished its claws." << endl;
        }
        else if (dialogue == 2) {
            cout << "> The Cyberpede let out a deafening howl." << endl;
        }
        else if (dialogue == 3) {
            cout << "> The Cyberpede looks like it's in pain." << endl;
        }
        else {
            cout << "> The Cyberpede's metalic body rattled noisily." << endl;
        }
    }
    else if (cpuMonster == 2) {
        if (dialogue == 1) {
            cout << "> The Shadowman gave a menacing smile." << endl;
        }
        else if (dialogue == 2) {
            cout << "> \"..." << name << "...\"" << endl;
        }
        else if (dialogue == 3) {
            cout << "> You're hearing voices." << endl;
        }
        else {
            cout << "> The Shadowman stared you down." << endl;
        }
    }
    else {
        if (dialogue == 1) {
            cout << "> Fluid oozed from an orifice." << endl;
        }
        else if (dialogue == 2) {
            cout << "> The Nasty Slime appears everywhere you look." << endl;
        }
        else if (dialogue == 3) {
            cout << "> The Nasty Slime edges closer." << endl;
        }
        else {
            cout << "> The Nasty Slime coughed up a pile of bones." << endl;
        }
    }
}

int main() {
    
    //Variables:
    string playerName;
    string favoriteThing;
    string stringOfSpaces;
    string cpuName;
    string yesOrNo;
    const string spaceString = " ";
    int numSpacesNeeded = 0;
    int userAct;
    int shieldDuration = -1;
    int cpuChoice;
    int dialogueChoice;
    int userSpeed;
    int cpuHealth;
    int cpuOffense;
    int cpuDefense;
    char userPsi;
    bool doneWithName = false; //For valid input check
    bool doneWithThings = false; //For valid input check
    bool doneWithPsi = false; //For valid input check
    bool firstGame = true;
    bool wantsToPlay = true;
    bool entryIsValid; //For the very end
    srand(time(0));
    
    //Introduction
    cout << "\nWelcome valued test subject, you have been selected to participate in a harmless combat exercise!" << endl;
    cout << "Why you may ask? Well it has do to with your unique psionic abilities of course! You are truly one of a kind," << endl;
    cout << "and these abilities of yours have really peaked the interest of the military, lucky you!" << endl;
    cout << "Now before we get started, allow me to ask you a few questions:\n> What is your name?" << endl;
    cout << "  Input 8 characters or less: ";
    getline(cin, playerName);
    
    while (doneWithName != true) { //---> Makes sure the "*" in the interface border is lined up right for the signature move name "thing".
        if (playerName.size() > 8) {
            cout << "  Your entry exceeded the max number of characters.\n  Please input 8 characters or less: ";
            getline(cin, playerName);
            
            doneWithName = false;
        }
        else {
            doneWithName = true;
        }
    }
    
    cout << "\n> What is your favorite thing?\n  Input 8 characters or less: ";
    getline(cin, favoriteThing);
    
    while (doneWithThings != true) { //---> Makes sure the "*" in the interface border is lined up right for the signature move name "thing".
        if (favoriteThing.size() > 8) {
            cout << "  Your entry exceeded the max number of characters.\n  Please input 8 characters or less: ";
            getline(cin, favoriteThing);
            
            doneWithThings = false;
        }
        else {
            numSpacesNeeded = 8 - favoriteThing.size();
            
            for (int i = 0; i < numSpacesNeeded; ++i) {
                stringOfSpaces.append(spaceString);
                
                doneWithThings = true;
            }
        }
    }

    cpuChoice = (rand() % 3) + 1;
    while (wantsToPlay == true) {
        //Initialize characters
        if (cpuChoice == 1) {
            cpuName = "Cyberpede";
            userSpeed = 32;
            cpuHealth = 37;
            cpuOffense = 5;
            cpuDefense = 6;
        }
        else if (cpuChoice == 2) {
            cpuName = "Shadowman";
            userSpeed = 2;
            cpuHealth = 38;
            cpuOffense = 3;
            cpuDefense = 5;
        }
        else {
            cpuName = "Nasty Slime";
            userSpeed = 32;
            cpuHealth = 42;
            cpuOffense = 4;
            cpuDefense = 6;
        }
        //  variable_name(name, offense, defense, health, speed, psi, shield, status)
        character player(playerName, 6, 2, 30, userSpeed, 20, false, false); //Player character
        character computer(cpuName, cpuOffense, cpuDefense, cpuHealth, 26, 0, false, false); //Computer character
    
        const int basePlayerHp = player.getHealth(); //For display purposes
        const int basePlayerPp = player.getPsyPoints(); //For display purposes
        
        if (firstGame == true) {
            cout << endl;
            cout << "Great! Now that we have all of that taken care of, let's get started!" << endl;
            cout << "\"COMBAT SIMULATION ACTIVATED\"" << endl;
        }
        cout << "\nYou engaged the " << computer.getName() << "!\n" << endl;
            
        while(player.isAlive() && computer.isAlive()) { //While the player and computer are both alive, they will fight
            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 3);
            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
            
            if (player.getSpeed() > computer.getSpeed()) { //---> Checks if the player is fast enough to attack first.
                while (doneWithPsi != true) {
                    cin >> userAct;
                    
                    if ((userAct == 1) || (userAct == 3)) { //---> The player bashed or checked.
                        cout << endl;
                        cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                        
                        computer = fightOrCheck(player, computer, userAct, (rand() % 10) + 1);
                        
                        doneWithPsi = true;
                    }
                    else if (userAct == 2) { //---> The player used psychic powers.
                        displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 2);
                        cin >> userPsi;
                    
                        if (((userPsi == 'A') || (userPsi == 'a')) && (player.getPsyPoints() >= 10)) { //---> The player used personalized psychic attack..
                            cout << endl;
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            
                            player.setPP(10);
                            cout << "> " << player.getName() << " used PSI " << favoriteThing << " and unleashed a psychokinetic wave!" << endl;
                            computer.psychoKinesis();
                            
                            doneWithPsi = true;
                        }
                        else if (((userPsi == 'B') || (userPsi == 'b')) && (player.getPsyPoints() >= 6)) { //---> The player used PSI Healing.
                            cout << endl;
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            player.setPP(6);
                            player.psionics(basePlayerHp);
                            
                            doneWithPsi = true;
                        }
                        else if (((userPsi == 'C') || (userPsi == 'c')) && (player.getPsyPoints() >= 4)) { //---> The player used PSI Shield.
                            cout << endl;
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            player = psiShieldOrCure(player, 4, false, false);
                            shieldDuration = 2;
                            
                            doneWithPsi = true;
                        }
                        else if (((userPsi == 'D') || (userPsi == 'd')) && (player.getPsyPoints() >= 2)) { //---> The player used PSI Cure.
                            cout << endl;
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            player = psiShieldOrCure(player, 2, false, true);
                            
                            doneWithPsi = true;
                        }
                        else if ((player.getPsyPoints() < 10) && ((userPsi == 'A') || (userPsi == 'a'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else if ((player.getPsyPoints() < 6) && ((userPsi == 'B') || (userPsi == 'b'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else if ((player.getPsyPoints() < 4) && ((userPsi == 'C') || (userPsi == 'c'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else if ((player.getPsyPoints() < 2) && ((userPsi == 'D') || (userPsi == 'd'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else { //---> The player did not enter the correct character value.
                            cout << "Entry is invalid." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                    }
                    else { //---> The player did not enter the correct integer value.
                        cin.clear(); // I'm not exactly sure what purpose these two serve,
                        cin.ignore(); // I just know it wouldn't work without it.
                        
                        cout << "Entry is invalid." << endl;
                        displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                        
                        doneWithPsi = false;
                    }
                }
                
                if (computer.getHealth() == 0) { //Can't do anything if you're dead.
                    break;
                }
                player = computerCombat(computer, player, cpuChoice, (rand() % 10) + 1, player.hasStat(), favoriteThing); //Computer attacking the player last
                
                if (shieldDuration > 0) { //---> Updates shield duration.
                    shieldDuration = shieldDuration - 1;
                }
                else if ((shieldDuration == 0) && (player.getHealth() > 0) && (player.getShield() == true)) {
                    player = psiShieldOrCure(player, 0, true, false);
                    shieldDuration = -1;
                }
                cout << endl;
                
                doneWithPsi = false;
            }
            else { //---> The computer is faster and goes first.
                while (doneWithPsi != true) {
                    cin >> userAct;
                    
                    if ((userAct == 1) || (userAct == 3)) { //---> The player bashed or checked.
                        cout << endl;
                        player = computerCombat(computer, player, cpuChoice, (rand() % 10) + 1, player.hasStat(), favoriteThing); //Computer attacking the player first
                        
                        if (player.getHealth() == 0) { //Can't do anything if you're dead.
                            break;
                        }
                        computer = fightOrCheck(player, computer, userAct, (rand() % 10) + 1);
                        cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                        
                        doneWithPsi = true;
                    }
                    else if (userAct == 2) { //---> The player used psychic powers.
                        displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 2);
                        cin >> userPsi;
                    
                        if (((userPsi == 'A') || (userPsi == 'a')) && (player.getPsyPoints() >= 10)) { //---> The player used personalized psychic attack.
                            cout << endl;
                            player = computerCombat(computer, player, cpuChoice, (rand() % 10) + 1, player.hasStat(), favoriteThing); //Computer attacking the player first
                            
                            if (player.getHealth() == 0) { //Can't do anything if you're dead.
                                break;
                            }
                            
                            player.setPP(10);
                            cout << "> " << player.getName() << " used PSI " << favoriteThing << " and unleashed a psychokinetic wave!" << endl;
                            computer.psychoKinesis();
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            
                            doneWithPsi = true;
                        }
                        else if (((userPsi == 'B') || (userPsi == 'b')) && (player.getPsyPoints() >= 6)) { //---> The player used PSI Healing.
                            cout << endl;
                            player = computerCombat(computer, player, cpuChoice, (rand() % 10) + 1, player.hasStat(), favoriteThing); //Computer attacking the player first
                            
                            if (player.getHealth() == 0) { //Can't do anything if you're dead.
                                break;
                            }
                            
                            player.setPP(6);
                            player.psionics(basePlayerHp);
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            
                            doneWithPsi = true;
                        }
                        else if (((userPsi == 'C') || (userPsi == 'c')) && (player.getPsyPoints() >= 4)) { //---> The player used PSI Shield.
                            cout << endl;
                            player = computerCombat(computer, player, cpuChoice, (rand() % 10) + 1, player.hasStat(), favoriteThing); //Computer attacking the player first
                            
                            if (player.getHealth() == 0) { //Can't do anything if you're dead.
                                break;
                            }
                            
                            player = psiShieldOrCure(player, 4, false, false);
                            shieldDuration = 3;
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            
                            doneWithPsi = true;
                        }
                        else if (((userPsi == 'D') || (userPsi == 'd')) && (player.getPsyPoints() >= 2)) { //---> The player used PSI Cure.
                            cout << endl;
                            player = computerCombat(computer, player, cpuChoice, (rand() % 10) + 1, player.hasStat(), favoriteThing); //Computer attacking the player first
                            
                            if (player.getHealth() == 0) { //Can't do anything if you're dead.
                                break;
                            }
                            
                            player = psiShieldOrCure(player, 2, false, true);
                            cpuDialogue(player.getName(), cpuChoice, (rand() % 4) + 1);
                            
                            doneWithPsi = true;
                        }
                        else if ((player.getPsyPoints() < 10) && ((userPsi == 'A') || (userPsi == 'a'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else if ((player.getPsyPoints() < 6) && ((userPsi == 'B') || (userPsi == 'b'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else if ((player.getPsyPoints() < 4) && ((userPsi == 'C') || (userPsi == 'c'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else if ((player.getPsyPoints() < 2) && ((userPsi == 'D') || (userPsi == 'd'))) { //---> The player did not have enough PP.
                            cout << "Not enough psychic points." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                        else { //---> The player did not enter the correct character value.
                            cout << "Entry is invalid." << endl;
                            displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                            
                            doneWithPsi = false;
                        }
                    }
                    else { //---> The player did not enter the correct integer value.
                        cin.clear(); // I'm not exactly sure what purpose these two serve,
                        cin.ignore(); // I just know it wouldn't work without it.
                        cout << "Entry is invalid." << endl;
                        displayInterface(player, basePlayerHp, basePlayerPp, favoriteThing, stringOfSpaces, 1);
                        
                        doneWithPsi = false;
                    }
                }
                if (shieldDuration > 0) { //---> Updates shield duration.
                    shieldDuration = shieldDuration - 1;
                }
                else if ((shieldDuration == 0) && (player.getHealth() > 0) && (player.getShield() == true)) {
                    player = psiShieldOrCure(player, 0, true, false);
                    shieldDuration = -1;
                }
                cout << endl;
                
                doneWithPsi = false;
            }
        }
        
        firstGame = false;
        //Evaluate winner
        if ((player.getHealth() > 0) && (computer.getHealth() == 0)) {
            cout << "> The " << computer.getName() << " took mortal damage!" << endl;
            cout << "> " << player.getName() << " defeated the " << computer.getName() << ".\n  YOU WON!" << endl;
            cout << "\nContinue? (\"Yes\" or \"No\")" << endl;
        }
        else {
            cout << "> " << player.getName() << " got hurt and collapsed!\n" << "  You lost..." << endl;
            cout << "\nTry again? (\"Yes\" or \"No\")" << endl;
        }
        
        entryIsValid = false;
        while (entryIsValid != true) {
            cout << "Answer: ";
            cin >> yesOrNo;
            if ((yesOrNo == "Yes") || (yesOrNo == "yes")) {
                wantsToPlay = true;
                entryIsValid = true;
                firstGame = false;
                
                cout << "\n\"REACTIVATING COMBAT SIMULATION\"" << endl;
                
                cin.clear();
                cin.ignore();
                
                if (cpuChoice == 1) {
                    cpuChoice = 2;
                }
                else if (cpuChoice == 2) {
                    cpuChoice = 3;
                }
                else {
                    cpuChoice = 1;
                }
            }
            else if ((yesOrNo == "No") || (yesOrNo == "no")) {
                cout << "\n*******RPG Assignment********\n* Class: ECGR-2104          *" << endl;
                cout << "* Programmer: Adriel Campos *\n* Thanks for playing!       *" << endl; 
                cout << "*****************************\n" << endl; //Credits
                wantsToPlay = false;
                entryIsValid = true;
            }
            else {
                cout << "Invalid entry, please type \"Yes\" or \"No\"." << endl;
                entryIsValid = false;
            }
        }
    }
    
    return 0;
}
