#ifndef LANDS_H// *****EXAMPLE CODE*****
#define LANDS_H

#include <string>
#include <stdlib.h>
#include "player.h"

using namespace std;

class Land {
    public:
        virtual string getShortDescription() = 0;// Virtual lets you use the overridden version
        virtual string getLongDescription() = 0; // "= 0" is the hallmark of the pure virtual function,
        virtual string visit(Player &p) = 0;     // making it so that you can only use the overridden versions
    
    private:
};

class Lake : public Land {// Derived class: Lake, Base class: Land
    public:
        string getShortDescription();//Overrides pure virtual function
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

class Forest : public Land {
    public:
        string getShortDescription();
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

class Cave : public Land {// New land type
    public:
        string getShortDescription();
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

class Desert : public Land {// New land type
    public:
        string getShortDescription();
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

class Boneyard : public Land {// New land type
    public:
        string getShortDescription();
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

class Town : public Land {// New land type
    public:
        string getShortDescription();
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

class AncientRuins : public Land {// New land type
    public:
        string getShortDescription();
        string getLongDescription();
        string visit(Player &p);
    
    private:
};

Land* getRandomLand(void);


#endif
