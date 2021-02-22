#ifndef OURGAME_LIVING_H
#define OURGAME_LIVING_H

#include "string"
#include <iostream>
#include <vector>
#include "items.h"
#include "spells.h"
using namespace std;
class Debuff;

#define LEVEL_TWO 500
#define LEVEL_THREE 1000
#define LEVEL_FOUR 1500
#define LEVEL_FIVE 2000
#define BASIC_EXP 100
#define STANDARD_GOLD 100

class Living{
protected:
    double max_healthPower;
    double current_hp;
    string name;
    int level;
    double agility;
public:
    Living(string, int ,double, double);
    string get_name();
    virtual void lose_life(int damage)=0;
    double get_agility(){
        return agility;
    }
    bool IsAlive();
    virtual void regenerate()=0;
    void setAgility(double agility);
    int get_lvl();
};

class Monster; //Class Forwarding,it helps so attack() function takes Monster pointer as argument;
//class Spell;
class Hero: public Living{

protected:
    int magicPower;
    int current_magic_power;
    int money;
    int strength;
    double dexterity;
    int exp;
    vector<Item*> Inventory;
    Build B;
    Spell* Abilities[4];

public:
    Hero(const string&, double, double,int, double);
    virtual void level_up()=0;
    void lose_money();
    void revive();
    void regenerate();
    int get_money();
    void reduce_money(int );
    void increase_money(int );
    void place_to_bag(Item*);
    void learn_new_spell(Spell*);
    int Inventory_size();
    vector<Item*> get_Inventory();
    void display_inventory();
    Item* remove_from_Inv(int n);
    void display_stats();
    void attack(Monster*);
    void equip();
    void wear(Item* ptr);
    void lose_life(int damage);
    void use_pot(Potion *);
    vector <Potion *>display_pots();
    int display_spells();
    Debuff * use_spell(int, Monster *, int);
    bool has_any_spells();
    Spell* remove_spell(int );
    void gain_exp(int );
    void lose_mana(int);
};


class Warrior: public Hero{
public:
    Warrior(string name);
    void level_up();
};

class Paladin : public Hero{
public:
    Paladin(string name);
    void level_up();
};


class Sorcerer: public Hero{
public:
    Sorcerer(string);
    void level_up();
};


class Monster : public Living{
protected:
    int min_damage;
    int max_damage;
    int defence;
public:
    Monster(string m_name="", int lvl=1, double hp=1.0, double agil=2.0, int min_dmg=2, int max_dmg=1, int def=1);
    void display_stats();
    void lose_life(int damage);
    void attack(Hero*);
    int getMinDamage() const;
    int getMaxDamage() const;
    int getDefence() const;
    void setMinDamage(int minDamage);
    void setMaxDamage(int maxDamage);
    void setDefence(int defence);
    void regenerate();

};

class Dragon : public Monster {
public:
    Dragon(string, int, double, double, int, int, int);
    static Dragon *Construct_Dragon(string, int);
};

class Exoskeleton: public Monster{
public:
    Exoskeleton(string, int, double, double, int, int, int);
    static Exoskeleton *Construct_Exoskeleton(string, int);
};

class Spirit : public Monster{
public:
    Spirit(string, int, double, double, int, int, int);
    static Spirit *Construct_Spirit(string, int);
};

#endif