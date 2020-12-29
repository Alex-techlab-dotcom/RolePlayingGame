#include "items.h"
#include <string>
#include <vector>
#include "spells.h"
#include <fstream>
#include "grid.h"
using namespace std;


class Shop{
private:
    vector <Weapon> Weapons;
    vector <Spell>  Spells;
    vector <Armor> Armors;
    vector <Potion> Potions;

public:
    Shop(const string& W, const string& A,const string& P,const string& S);
    void enter_shop(CompanyOfHeroes* c);
};
