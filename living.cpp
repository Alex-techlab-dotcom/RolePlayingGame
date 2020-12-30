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

void Hero::increaze_money(int n)
{
    money+=n;
}

void Hero::place_to_bag(Item* i)
{
    Inventory.push_back(i);
}

void Hero::learn_new_spell(Spell* s)
{
    for (int i = 0; i <4 ; ++i) {
        if (Abilities[i] == nullptr)
        {
            Abilities[i]=s;
        }
    }
}

int Hero::Inventory_size()
{
    return Inventory.size();
}

vector<Item*> Hero::get_Inventory()
{
    return Inventory;
}

void Hero::display_inventory()
{
    for (int i = 0; i <Inventory_size() ; ++i) {
        cout << i+1 << ")" << "\n";
        Inventory[i]->print_Item();
        cout << "\n\n";
    }
}

Item* Hero::remove_from_Inv(int n)
{
    Item *ptr=Inventory[n-1];
    Inventory.erase(Inventory.begin()+n-1);
    cout << "size " << Inventory.size() << "\n";
    return ptr;
}