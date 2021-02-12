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
    virtual void print();
    virtual void battle_display()=0;
    int get_min_lvl();
    int getMinDamage() const;

    int getMaxDamage() const;
    virtual int getRounds() const=0;
    virtual double getDebuff()const=0;
};

//debuffs are given as positive real numbers from 0 to 1 that translate to percentages (ex armor_debuff=0.1 -10% effect)

class IceSpell :public Spell{
private:
    double damage_debuff;
    int rounds;
public:
    IceSpell(std::string, int, int, int, int, int, double, int);
    void print();
    virtual void battle_display();

    int getRounds() const;
    double getDebuff() const;

};

class FireSpell : public Spell{
    double defence_debuff;
    int rounds;
public:
    FireSpell(std::string, int, int, int, int, int, double, int);
    void print();
    virtual void battle_display();

    int getRounds() const;
    double getDebuff() const;

};

class LightingSpell : public Spell{
    double agility_debuff;
    int rounds;
public:
    LightingSpell(std::string, int, int, int, int, int, double, int);
    void print();
    virtual void battle_display();

    int getRounds() const;
    double getDebuff() const;
};

#endif
