#ifndef OURGAME_SPELLS_H
#define OURGAME_SPELLS_H

#include <iostream>
#include <string>

class Spell{ //MAKE IT ABSTRACT
protected:
    std::string name;
    int price;
    int min_level;
    int mana_cost;
    int min_damage;
    int max_damage;
public:
    Spell(std::string, int, int, int, int, int);
    std::string get_name();
    int get_price();
    void get(int &m_level,int& mana_c,int& min_dmg,int& max_dmg);
    virtual void print()=0;
    void print_basic();
};

//debuffs are given as positive real numbers from 0 to 1 that translate to percentages (ex armor_debuff=0.1 -10% effect)

class IceSpell :public Spell{
private:
    double dexterity_debuff;
    int rounds;
public:
    IceSpell(std::string, int, int, int, int, int, double, int);
    void print();
};

class FireSpell : public Spell{
    double armor_debuff;
    int rounds;
public:
    FireSpell(std::string, int, int, int, int, int, double, int);
    void print();
};

class LightingSpell : public Spell{
    double agility_debuff;
    int rounds;
public:
    LightingSpell(std::string, int, int, int, int, int, double, int);
    void print();
};
#endif
