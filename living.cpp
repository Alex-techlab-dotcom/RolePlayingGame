#include "living.h"

//LIVING
Living::Living(string lname,int lvl, double hp, double agil)
{
    name=lname;
    level=lvl;
    max_healthPower=hp;
    current_hp=max_healthPower;
    agility=agil;
}

string Living::get_name(){
    return name;
}

//WARRIOR

Warrior::Warrior(string w_name):Hero(w_name, 200, 0.25, 75, 0.05)
{
    cout << "A new warrior named as " << name << " has been created\n";
}

void Warrior::level_up()
{
    level++;
    cout << "The prideful warrior " << name << " has now reached level " << level << "\n";
    strength+=40;
    agility+=0.07;
    dexterity+=0.04;
}

//PALADIN

Paladin::Paladin(string p_name):Hero(p_name, 200, 0.1, 75, 0.2)
{
    cout << "A new paladin named as " << name << " has been created\n";
}

void Paladin::level_up()
{
    level++;
    cout << "The glorious paladin " << name << " has now reached level " << level << "\n";
    strength+=40;
    agility+=0.04;
    dexterity+=0.07;
}

//SORCERER
Sorcerer::Sorcerer(string s_name):Hero(s_name, 200, 0.25, 50, 0.2)
{
    cout << "A new sorcerer named as " << name << " has been created\n";
}

void Sorcerer::level_up()
{
    level++;
    cout << "The legendary sorcerer " << name << " has now reached level " << level << "\n";
    strength+=30;
    agility+=0.07;
    dexterity+=0.07;
}

//HERO

Hero::Hero(string h_name, double hp, double agil, int str, double dext):Living(name, 1, hp, agil)
{
    exp=0;
    magicPower=100;
    money=1200;
}

void Hero::lose_money()
{
    // after each defeated battle the hero looses half of his money!
    money=money/2;
}

void Hero::regenerate_health()
{
    current_hp+= max_healthPower*0.2;

    //we dont want to regenerate more hp than the hero initially has!
    if (current_hp>max_healthPower)current_hp=max_healthPower;
}

int Hero::get_money()
{
    return money;
}

void Hero::reduce_money(int money_to_subtract)
{
    money-=money_to_subtract;
}

void Hero::increase_money(int n)
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

void Hero::display_stats(){
    cout << name << endl;
    cout << level << endl;
    cout << "XP: " << exp << endl;
    cout << "HP : " << current_hp << "/" << max_healthPower <<endl;
    cout << "Mana: " << magicPower << endl;
    cout << "Agility: " << agility << endl;
    cout << "Dexterity: " << dexterity << endl;
}

//MONSTER
Monster::Monster(string m_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Living(m_name, lvl, hp, agil)
{
    min_damage=min_dmg;
    max_damage=max_dmg;
    defence=def;
}

void Monster::display_stats(){
    cout << "Name: " << name << endl;
    cout << "Level: " << level <<endl;
    cout << "HP : " << current_hp << "/" << max_healthPower <<endl;
    cout << "Attack: " << min_damage<< " - "<<max_damage<< endl;
    cout << "Defence: " << defence << endl;
}

//DRAGON
Dragon::Dragon(string d_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Monster(d_name, lvl, hp, agil, min_dmg, max_dmg, def)
{
}

Dragon * Dragon::Construct_Dragon(string name, int lvl) {
    switch(lvl){
        case 3:
            return  new Dragon(name, 3, 1000, 0.2, 170, 220, 150);
        case 2:
             return  new Dragon(name, 2, 450, 0.1, 100, 140, 50);
        default:
             return new Dragon(name, 1, 200, 0, 50, 80, 0);
    }
}

//EXOSKELETON
Exoskeleton::Exoskeleton(string e_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Monster(e_name, lvl, hp, agil, min_dmg, max_dmg, def)
{
}

Exoskeleton * Exoskeleton::Construct_Exoskeleton(string name, int lvl)
{
    switch(lvl){
    case 3:
        return new Exoskeleton(name, 3, 1000, 0.2, 135, 180, 180);
    case 2:
        return new Exoskeleton(name, 2, 450, 0.1, 60, 110, 100);
    default:
        return new Exoskeleton(name, 1, 200, 0, 30, 50, 60);
    }
}

//SPIRIT
Spirit::Spirit(string s_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Monster(s_name, lvl, hp, agil, min_dmg, max_dmg, def)
{
}

Spirit * Spirit::Construct_Spirit(string name, int lvl)
{
    switch(lvl){
    case 3:
        return new Spirit(name, 3, 1000, 0.5, 135, 180, 150);
    case 2:
        return new Spirit(name, 2, 450, 0.3, 60, 110, 50);
    default:
        return new Spirit(name, 1, 200, 0.2, 30, 50, 0);
    }
}