#include "living.h"

//LIVING
string Living::get_name(){
    return name;
}

void Warrior::level_up()
{
    level++;
    cout << "The prideful warrior " << name << " has now reached level " << level << "\n";
    strength+=100;
    agility+=100;
    dexterity+=30;
}

void Paladin::level_up()
{
    level++;
    cout << "The glorious paladin " << name << " has now reached level " << level << "\n";
    strength+=100;
    agility+=30;
    dexterity+=100;
}
void Sorcerer::level_up()
{
    level++;
    cout << "The legendary sorcerer " << name << " has now reached level " << level << "\n";
    strength+=30;
    agility+=100;
    dexterity+=100;
}

//------------------------------------------------------------------------------------------------------------------//

void Hero::lose_money()
{
    // after each defeated battle the hero looses half of his money!
    money=money/2;
}

void Hero::regenerate_health()
{
    current_hp+= max_healthpower*0.2;

    //we dont want to regenerate more hp than the hero initially has!
    if (current_hp>max_healthpower)current_hp=max_healthpower;
}

int Hero::get_money()
{
    return money;
}

void Hero::reduce_money(int money_to_subtract)
{
    money-=money_to_subtract;
}
void Hero::place_to_bag(Item* i)
{
    Inventory.push_back(i);
}

void Hero::learn_new_spell(Spell* s)
{
    for (int i = 0; i <5 ; ++i) {
        if (Abilities[i] == nullptr)
        {
            Abilities[i]=s;
        }
    }
}