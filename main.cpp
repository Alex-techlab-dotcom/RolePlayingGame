#include "shop.h"
#include <vector>
using namespace std;

int main() {


    Warrior* w1= new Warrior("Alex");
    Paladin* p1=new Paladin("tasos");
    CompanyOfHeroes* c= new CompanyOfHeroes(w1,p1);
    Shop S("Weapon.txt","Armor.txt","Potions.txt","spells.txt");
    S.enter_shop(c);

}
