#include "spells.h"

//SPELL
Spell::Spell(std::string s_name, int s_price, int s_min_level, int s_mana_cost, int s_min, int s_max) {
    name=s_name;
    price=s_price;
    min_level=s_min_level;
    mana_cost=s_mana_cost;
    min_damage=s_min;
    max_damage=s_max;
}
std::string Spell::get_name()
{
    return name;
}

int Spell::get_price() {
    return price;
}
void Spell::get(int &m_level, int &mana_c, int &min_dmg, int &max_dmg)
{
    m_level=min_level;
    mana_c=mana_cost;
    min_dmg=min_damage;
    max_dmg=max_damage;
}

void Spell::print_basic()
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Price: " << price<< "\n";
    std::cout << "Minimun level: " << min_level<< "\n";
    std::cout << "Min damage: " << min_damage<< "\n";
    std::cout << "Max damage: " << max_damage<< "\n";
    std::cout <<  "Mana cost: " << mana_cost<< "\n";
}
//ICE SPELL
IceSpell::IceSpell(std::string is_name, int is_price, int is_min_level, int is_mana_cost, int is_min, int is_max, double  is_dex, int is_rounds):Spell(is_name, is_price, is_min_level, is_mana_cost, is_min, is_max) {
    dexterity_debuff=is_dex;
    rounds=is_rounds;
}
void IceSpell::print()
{
    print_basic();
    std::cout<<"Dexterity Debuff: " << dexterity_debuff;
    std::cout <<"Duration: " << rounds << " rounds\n";
}

//FIRE SPELL
FireSpell::FireSpell(std::string fs_name, int fs_price, int fs_min_level, int fs_mana_cost, int fs_min, int fs_max, double  fs_arm, int fs_rounds):Spell(fs_name, fs_price, fs_min_level, fs_mana_cost, fs_min, fs_max) {
    armor_debuff=fs_arm;
    rounds=fs_rounds;
}
void FireSpell::print()
{
    print_basic();
    std::cout<<"Armor Debuff: " << armor_debuff;
    std::cout <<"Duration: " << rounds << " rounds\n";
}

//LIGHTING SPELL
LightingSpell::LightingSpell(std::string ls_name, int ls_price, int ls_min_level, int ls_mana_cost, int ls_min, int ls_max, double  ls_ag, int ls_rounds):Spell(ls_name, ls_price, ls_min_level, ls_mana_cost, ls_min, ls_max) {
    agility_debuff=ls_ag;
    rounds=ls_rounds;
}
void LightingSpell::print()
{
    print_basic();
    std::cout<<"Agility Debuff: " <<agility_debuff;
    std::cout <<"Duration: " << rounds << " rounds\n";
}