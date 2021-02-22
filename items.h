#ifndef OURGAME_ITEMS_H
#define OURGAME_ITEMS_H

#include <iostream>
#include <string>

class Item{ //MAKE IT ABSTRACT
private:
      std::string name;
      int price;
      int sell_price;
      int min_level;
public:
    Item(std::string, int, int);
    virtual ~Item()=0;
    virtual void print_Item()=0;
    void get( std::string& lname,int& lprice,  int& lmin_level,int& sell_price2);
    int  get_price();
    std::string get_name();
    int get_min_lvl();
};

class Weapon : public Item{
private:
    int damage_per_attack;
    int two_hands_needed;
public:
    Weapon(std::string, int, int, int, int);
    void print_Item();
    int get_damage();
    int two_hands();
};

class Armor : public Item{
private:
    double damage_reduction; //holds values from 0 - 1 percentage of the damage that is being absorbed
public:
    Armor(std::string, int, int, double);
    void print_Item();
    double get_damage_reduction();
};

//a potion can be used only once, after the first use needs to be destroyed
class Potion : public Item{
private:
    //hp and mana pots add raw stats (ex. pot +300 mana), other pots add percentage (ex agility pot -> agility_buff=0.03->3% agility buff)
    int hp_buff;
    int mana_buff;
    double agility_buff;
    double strength_buff;
    double dexterity_buff;
public:
    Potion(std::string, int, int, int , int, double, double, double);
    void print_Item();
    void print_use();
    void buff_stats(double &, int &, double &, int &, double &);

};


class Build{
    friend class Hero;
private:
    Weapon* left_hand;
    Weapon* right_hand;
    Armor* chest;
public:
    Build(Weapon* l= nullptr,Weapon* r= nullptr,Armor* a= nullptr);
};


#endif