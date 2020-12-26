#include "string"
#include <iostream>
using namespace std;

class Living{
protected:
    int armor;
    int agility
    double max_healthpower;
    double current_hp;
    string name;
    int level;
public:
    Living(string onoma,int lvl=1,double hp=500):name(onoma),level(lvl),max_healthpower(hp),current_hp(hp)
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
    int strenght;
    int agility;
    int dexterity;
    int xp;
    //Item Inventory
    //Item Build
public:
    Hero(string name):Living(name)
    {
        mana=100;
        money=100;
    }
    virtual void level_up()=0;
    void loose_money();
    void regenerate_health();
};

class Warrior: public Hero{
public:
    Warrior(string name):Hero(name)
    {
        strenght=100;
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
        strenght=100;
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
        strenght=30;
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
        armor=100;
        attack_damage=300;
        agility=50;
    }
};

class Exoskeleton: public Monster{
public:
    Exoskeleton(string name):Monster(name)
    {
        armor=300;
        attack_damage=100;
        agility=50;
    }
};

class Spirit : public Monster{
public:
    Spirit(string name):Monster(name)
    {
        armor=50;
        agility=300;
        attack_damage=100;
    }
};
