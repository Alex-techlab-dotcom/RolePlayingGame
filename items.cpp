#include "items.h"
using namespace std;
//ITEM
Item::Item(std::string i_name, int i_price, int i_min_level){
    name=i_name;
    price=i_price;
    min_level=i_min_level;
    sell_price=price/2;
}

void Item::get(std::string& lname, int& lprice,  int& lmin_level,int& sell_price2)
{
    lname=name;
    lprice=price;
    lmin_level=min_level;
    sell_price2=sell_price;
}

int Item::get_price()
{
    return price;
}

string Item::get_name()
{
    return name;
}

//WEAPON
Weapon::Weapon(std::string w_name, int w_price, int w_min_level, int w_damage, bool w_hands):Item(w_name, w_price, w_min_level){
    damage_per_attack=w_damage;
    two_hands_needed=w_hands;
}

void Weapon::print_Item()
{
    std::string name;
    int min_level,price,sell_price;
    this->get(name,price,min_level,sell_price);
    cout << "Weapon's name :" << name << "\n";
    cout << "Minimum level :" << min_level <<"\n";
    cout << "Price :" << price << " gold coins \n";
    cout << "Sell price :" << sell_price << " gold coins\n";
    cout << "Damage per hit :" << damage_per_attack << "\n";
    if (two_hands_needed)cout <<"Two Hands\n";
    else cout <<"One Hand\n";
}

//ARMOR
Armor::Armor(std::string a_name, int a_price, int a_min_level, double a_dmg_red):Item(a_name, a_price, a_min_level) {
    damage_reduction=a_dmg_red;
}

void Armor::print_Item()
{
    std::string name;
    int min_level,price,sell_price;
    this->get(name,price,min_level,sell_price);
    cout << "Armors's name :" << name << "\n";
    cout << "Minimum level :" << min_level <<"\n";
    cout << "Price :" << price << "gold coins \n";
    cout << "Damage reduction :" << damage_reduction*10 <<"%";
}

//POTION
Potion::Potion(std::string p_name, int p_price, int p_min_level, int p_hp, int p_mana, double p_agi, double p_str, double p_dext):Item(p_name, p_price, p_min_level)
{
    hp_buff=p_hp;
    mana_buff=p_mana;
    agility_buff=p_agi;
    strength_buff=p_str;
    dexterity_buff=p_dext;
}

void Potion:: Potion::print_Item() {
    std::string name;
    int min_level,price,sell_price;
    this->get(name,price,min_level,sell_price);
    cout << "Potions's name :" << name << "\n";
    cout << "Minimum level :" << min_level <<"\n";
    cout << "Price :" << price << "gold coins \n";
    cout << "Sell price :" << sell_price << " gold coins \n";
    if(hp_buff!=0)cout << "Health buff : " << hp_buff << " health points\n";
    else if(mana_buff!=0) cout << "Mana buff : " << mana_buff << " mana points\n";
    else if(agility_buff!=0) cout << "Agility buff : " << agility_buff*100 << "%\n";
    else if(strength_buff!=0) cout << "Strength buff : " << strength_buff*100 << "%\n";
    else cout << "Dexterity buff : " << dexterity_buff*100 << "%\n";
}