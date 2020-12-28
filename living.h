#include "string"
#include <iostream>
#include <vector>
#include "items.h"
using namespace std;

class Living{
protected:
    double armor;
    int agility;
    double max_healthpower;
    double current_hp;
    string name;
    int level;
public:
    Living(string lname,int lvl=1,double hp=500):name(lname),level(lvl),max_healthpower(hp),current_hp(hp)
    {
        armor=0;
        agility=0;
        //the constructor of living beings
    }
};

class Hero: public Living{
private:
    int mana;
    int money;
protected:
    int strength;
    int agility;
    int dexterity;
    int xp;
    vector<Item*> Inventory;
    vector<Item*> Build;

public:
    Hero(string name):Living(name)
    {
        mana=100;
        money=100;
    }
    virtual void level_up()=0;
    void lose_money();
    void regenerate_health();
};

class Warrior: public Hero{
public:
    Warrior(string name):Hero(name)
    {
        strength=100;
        agility=80;
        dexterity=30;
        cout << "A new warrior named as " << name << " has been created\n";
    }
    void level_up();
};

class Paladin : public Hero{
public:
    Paladin(string name):Hero(name)
    {
        strength=100;
        dexterity=100;
        agility=30;
        cout << "A new paladin named as " << name << " has been created\n";
    }
    void level_up();
};


class Sorcerer: public Hero{
public:
    Sorcerer(string name):Hero(name)
    {
        strength=30;
        dexterity=100;
        agility=100;
        cout << "A new sorcerer named as " << name << " has been created\n";
    }
    void level_up();
};


class Monster : public Living{
protected:
    int attack_damage;
public:
    Monster(string name):Living(name)
    {
        cout<< "A new dragon named as " << name << " has been awaken!";
    }
};

class Dragon : public Monster{
public:
    Dragon(string name):Monster(name)
    {
        armor=0.3;
        attack_damage=300;
        agility=50;
    }
};

class Exoskeleton: public Monster{
public:
    Exoskeleton(string name):Monster(name)
    {
        armor=0.4;
        attack_damage=100;
        agility=50;
    }
};

class Spirit : public Monster{
public:
    Spirit(string name):Monster(name)
    {
        armor=0.1;
        agility=300;
        attack_damage=100;
    }
};
