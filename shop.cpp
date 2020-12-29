#include "shop.h"

Shop::Shop(const string& W, const string& A,const string& P,const string& S){

    string name,num_of_hands;
    int price,dmg,lvl;
    //WEAPONS
    ifstream Weapons_file(W);

    while (Weapons_file>> name >> price >> lvl >> dmg >> num_of_hands){
        if (num_of_hands=="OneHand")
        {
            Weapon w(name,price,lvl,dmg, false);
            Weapons.push_back(w);
        }

    }
    //ARMORS
    ifstream Armor_File(A);
    double resistance;
    string name2;
    string space=" ";
    while (Armor_File>> name>> name2 >> price >> lvl >> resistance)
    {

        name+= space +name2;
        Armor a(name,price,lvl,resistance);
        Armors.push_back(a);

    }

    // Potion::Potion(std::string p_name, int p_price, int p_min_level, int p_hp, int p_mana, double p_agi, double p_str, double p_dext)
    ifstream Potions_File(P);
    int p_min_level, p_hp, p_mana;
    double p_agi,  p_str,  p_dext;
    while (Potions_File >> name >> price >> p_min_level >> p_hp >> p_mana >> p_agi >> p_str >>p_dext)
    {
        Potion p(name,price, p_min_level,  p_hp,  p_mana,  p_agi,  p_str,  p_dext);
        Potions.push_back(p);
    }


    ifstream  Spells_File(P);


}


void Shop::enter_shop(CompanyOfHeroes *c)
{
    cout << "WELCOME TO THE SHOP!\n\n";
    vector<Hero*> buyers;
    for (int i = 0; i <3 ; ++i) {
        if(c->get_Hero(i+1)!= nullptr)
        {
            buyers.push_back(c->get_Hero(i+1));
        }

    }
    //while( input != q)
    cout << "Choose the Hero who is going to buy\n";
        for (int i = 0; i <3 ; ++i) {

                    buyers.push_back(c->get_Hero(i+1));
                    cout << i+1 << "." << buyers[i]->get_name() << endl;

        }
        int number;
        cin >> number;// we choose which hero is going to buy;
            //while()
                //shop menu;
}