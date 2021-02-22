#ifndef OURGAME_SHOP_H
#define OURGAME_SHOP_H


#include "items.h"
#include <string>
#include <vector>
#include "spells.h"
#include "grid.h"
using namespace std;


class Shop{
private:
    vector <Weapon> Weapons;
    vector <Spell*>  Spells;
    vector <Armor> Armors;
    vector <Potion> Potions;

public:
    Shop();
    void enter_shop(CompanyOfHeroes* c);
    void delete_shop(){
        for (int i = 0; i <Spells.size() ; ++i) {
            delete Spells[i];
        }
    }
};

#endif