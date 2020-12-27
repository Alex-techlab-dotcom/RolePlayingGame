#include "items.h"

//ITEM
Item::Item(std::string i_name, int i_price, int i_min_level){
    name=i_name;
    price=i_price;
    min_level=i_min_level;
}

//WEAPON
Weapon::Weapon(std::string w_name, int w_price, int w_min_level, int w_damage, bool w_hands):Item(w_name, w_price, w_min_level){
    damage_per_attack=w_damage;
    two_hands_needed=w_hands;
}

//ARMOR
Armor::Armor(std::string a_name, int a_price, int a_min_level, double a_dmg_red):Item(a_name, a_price, a_min_level) {
    damage_reduction=a_dmg_red;
}

//POTION
Potion::Potion(std::string p_name, int p_price, int p_min_level, int p_hp, int p_mana, double p_agi, double p_str, double p_dext):Item(p_name, p_price, p_min_level) {
    hp_buff=p_hp;
    mana_buff=p_mana;
    agility_buff=p_agi;
    strength_buff=p_str;
    dexterity_buff=p_dext;
}