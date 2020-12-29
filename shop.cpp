#include "shop.h"
#include <fstream>
Shop::Shop(const string& W, const string& A,const string& P,const string& S){

    string name,num_of_hands;
    int price,dmg,lvl;
    //WEAPONS
    ifstream Weapons_file("weapons.txt");

    while (Weapons_file>> name >> price >> lvl >> dmg >> num_of_hands){

        if (num_of_hands=="OneHand")
        {
            Weapon w(name,price,lvl,dmg, false);
            Weapons.push_back(w);
        }else if(num_of_hands=="TwoHand"){
            Weapon w(name,price,lvl,dmg, true);
            Weapons.push_back(w);
        }

    }
    //ARMORS
    ifstream Armor_File("Armor.txt");
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
    ifstream Potions_File("Potions.txt");
    int p_min_level, p_hp, p_mana;
    double p_agi,  p_str,  p_dext;
    while (Potions_File >> name >> price >> p_min_level >> p_hp >> p_mana >> p_agi >> p_str >>p_dext)
    {
        Potion p(name,price, p_min_level,  p_hp,  p_mana,  p_agi,  p_str,  p_dext);
        Potions.push_back(p);
    }


   // ifstream  Spells_File(P);


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
    int selected_hero,category,Item_num;
    string answer="yes";

        while(answer=="yes")
        {
            cout << "Choose the Hero who is going to buy\n";
            for (int i = 0; i <3 ; ++i) {

                buyers.push_back(c->get_Hero(i+1));
                cout << i+1 << "." << buyers[i]->get_name() << endl;

            }

            cin >> selected_hero;// we choose which hero is going to buy;

            cout<<"Hey, " << buyers[selected_hero-1]->get_name() << " what are you looking for ?\n\n";
            string KeepBuying="yes";
            while(KeepBuying=="yes")
            {
                cout << "CATEGORIES: \n";
                cout << "1) Weapons!\n";
                cout << "2) Armor!\n";
                cout << "3) Potions!\n";
                cout << "4) Spells!\n";

                cin >> category;

                switch (category)
                {
                    case 1:
                        for (int i = 0; i < Weapons.size(); ++i)
                        {
                            cout << i+1 <<")";
                            Weapons[i].print_Item();
                            cout << "\n";
                        }

                        cout<< "Type the number of the item you want to buy\n";
                        cout<< "To exit Weapon's item list,type 0\n";
                        cin >> Item_num;
                        while (Item_num)
                        {
                            if (buyers[selected_hero-1]->get_money()>=Weapons[Item_num-1].get_price())//if u can afford the item
                            {
                                buyers[selected_hero-1]->reduce_money(Weapons[Item_num-1].get_price());
                                cout<<"Nice,you just bought " << Weapons[Item_num-1].get_name();
                                cout <<"You have " <<buyers[selected_hero-1]->get_money() <<" gold coins left!\n";
                            }else
                            {
                                cout << "I am sorry you do not have enough gold coins\n";
                                cout << Weapons[Item_num-1].get_price()-buyers[selected_hero-1]->get_money() << "gold coins missing\n";
                            }
                            cout<< "Type the number of the item you want to buy\n";
                            cout<< "To exit Armor's item list,type 0\n";
                            cin >> Item_num;
                        }
                        break;

                    case 2:
                        for (int i = 0; i < Armors.size(); ++i)
                        {
                            cout << i+1 <<")";
                            Armors[i].print_Item();
                            cout << "\n";
                        }

                        cout<< "Type the number of the item you want to buy\n";
                        cout<< "To exit Armor's item list,type 0\n";
                        cin >> Item_num;
                        while (Item_num)
                        {
                            if (buyers[selected_hero-1]->get_money()>=Armors[Item_num-1].get_price())//if u can afford the item
                            {
                                buyers[selected_hero-1]->reduce_money(Armors[Item_num-1].get_price());
                                cout<<"Nice,you just bought " << Armors[Item_num-1].get_name();
                                cout <<"You have " <<buyers[selected_hero-1]->get_money() <<" gold coins left!\n";
                            }else
                            {
                                cout << "I am sorry you do not have enough gold coins\n";
                                cout << Armors[Item_num-1].get_price()-buyers[selected_hero-1]->get_money() << "gold coins missing\n";
                            }

                            cout<< "Type the number of the item you want to buy\n";
                            cout<< "To exit Armor's item list,type 0\n";
                            cin >> Item_num;
                        }
                        break;
                }
                cout << "Hey " <<buyers[selected_hero-1]->get_name() << " do you want to buy something more?\n";
                cout << "Type 'yes' to continue...\n";
                cout << "Type 'no' to stop...\n";
                cin >>KeepBuying;
            }

            cout << "If you want to choose an other hero to buy items ,pres yes...\n";
            cout << "To exit shop, press exit..\n";
            cin>> answer;
        }


            //while()
                //shop menu;
}