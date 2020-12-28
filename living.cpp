#include "living.h"


void Warrior::level_up()
{
    level++;
    cout << "The pridefull warrior " << name << " has now reached level " << level << "\n";
    strenght+=100;
    agility+=100;
    dexterity+=30;
}

void Paladin::level_up()
{
    level++;
    cout << "The glorius paladin " << name << " has now reached level " << level << "\n";
    strenght+=100;
    agility+=30;
    dexterity+=100;
}
void Sorcerer::level_up()
{
    level++;
    cout << "The legendary sorcerer " << name << " has now reached level " << level << "\n";
    strenght+=30;
    agility+=100;
    dexterity+=100;
}

//------------------------------------------------------------------------------------------------------------------//

void Hero::loose_money()
{
    // after each defeated battle the hero looses half of his money!
    money=money/2;
}

void Hero::regenerate_health()
{
    current_hp+= max_healthpower*0.2;

    //we dodnt want to regenerate more hp than the hero initialy has!
    if (current_hp>max_healthpower)current_hp=max_healthpower;
}