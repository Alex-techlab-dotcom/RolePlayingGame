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
    while (Potions_File >> name >> name2 >> price >> p_min_level >> p_hp >> p_mana >> p_agi >> p_str >>p_dext)
    {
        name+=name2;
        Potion p(name,price, p_min_level,  p_hp,  p_mana,  p_agi,  p_str,  p_dext);
        Potions.push_back(p);
    }


    ifstream  Spells_File("Spells.txt");
    string type;
    int mana_cost,min_dmg,max_dmg,duration;
    double debuff;
//ceSpell::IceSpell(std::string is_name, int is_price, int is_min_level, int is_mana_cost, int is_min, int is_max, double  is_dex, int is_rounds)
    while (Spells_File >> name >> type >> price >> p_min_level >> mana_cost >>min_dmg >> max_dmg >> debuff >> duration)
    {
        if (type=="FireSpell")
        {
            FireSpell* f=new FireSpell(name,price,p_min_level,mana_cost,min_dmg,max_dmg,debuff,duration);
            Spells.push_back(f);
        }
        else if(type== "IceSpell")
        {
            IceSpell* i=new IceSpell(name,price,p_min_level,mana_cost,min_dmg,max_dmg,debuff,duration);
            Spells.push_back(i);
        }
        else{
                LightingSpell* l=new LightingSpell(name,price,p_min_level,mana_cost,min_dmg,max_dmg,debuff,duration);
                Spells.push_back(l);
            }
    }

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
            cout << "Choose the Hero \n";
            for (int i = 0; i <3 ; ++i) {

                buyers.push_back(c->get_Hero(i+1));
                cout << i+1 << "." << buyers[i]->get_name() << endl;

            }
            cout << "0.Exit\n";
            cin >> selected_hero;// we choose which hero is going to buy;

            if (selected_hero==0)break;

            cout<<"Hey, " << buyers[selected_hero-1]->get_name() << " what are you looking for ?\n\n";
            string KeepBuying="yes";
            while(KeepBuying=="yes")
            {
                cout << "CATEGORIES: \n";
                cout << "1) Weapons!\n";
                cout << "2) Armor!\n";
                cout << "3) Potions!\n";
                cout << "4) Spells!\n";
                cout << "5) Sell!\n";
                cout << "6) Stop buying with this character!\n";
                cin >> category;

                if(category==6)break;

                switch (category)
                {
                    case 1:
                        for (int i = 0; i < Weapons.size(); ++i)
                        {
                            cout << i+1 <<")";
                            Weapons[i].print_Item();
                            cout << "\n";
                        }
                        cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";

                        cout<< "Type the number of the item you want to buy\n";
                        cout<< "To exit Weapon's item list,type 0\n\n";
                        cin >> Item_num;
                        while (Item_num)
                        {
                            if (buyers[selected_hero-1]->get_lvl()>=Weapons[Item_num-1].get_min_lvl()){
                                if (buyers[selected_hero-1]->get_money()>=Weapons[Item_num-1].get_price())//if u can afford the item
                                {
                                    buyers[selected_hero-1]->reduce_money(Weapons[Item_num-1].get_price());
                                    cout<<"Nice,you just bought " << Weapons[Item_num-1].get_name();
                                    cout <<"You have " <<buyers[selected_hero-1]->get_money() <<" gold coins left!\n\n";
                                    buyers[selected_hero-1]->place_to_bag(&Weapons[Item_num-1]);
                                    cout << "num :" << buyers[selected_hero-1]->Inventory_size() << "\n\n";
                                }else
                                {
                                    cout << "I am sorry you do not have enough gold coins\n";
                                    cout << Weapons[Item_num-1].get_price()-buyers[selected_hero-1]->get_money() << " gold coins missing\n\n";
                                }
                            }else cout << "You are not the apropriate level\n\n";

                            cout<< "Type the number of the item you want to buy\n";
                            cout<< "To exit Weapon's item list,type 0\n\n";
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
                        cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";

                        cout<< "Type the number of the item you want to buy\n";
                        cout<< "To exit Armor's item list,type 0\n\n";
                        cin >> Item_num;
                        while (Item_num)
                        {
                            if (buyers[selected_hero-1]->get_lvl()>=Armors[Item_num-1].get_min_lvl()){
                                if (buyers[selected_hero-1]->get_money()>=Armors[Item_num-1].get_price())//if u can afford the item
                                {
                                    buyers[selected_hero-1]->reduce_money(Armors[Item_num-1].get_price());
                                    cout<<"Nice,you just bought " << Armors[Item_num-1].get_name();
                                    cout <<"You have " <<buyers[selected_hero-1]->get_money() <<" gold coins left!\n\n";
                                    cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";
                                    buyers[selected_hero-1]->place_to_bag(&Armors[Item_num-1]);
                                    cout << "num :" << buyers[selected_hero-1]->Inventory_size() << "\n\n";
                                }else
                                {
                                    cout << "I am sorry you do not have enough gold coins\n";
                                    cout << Armors[Item_num-1].get_price()-buyers[selected_hero-1]->get_money() << " gold coins missing\n\n";
                                }
                            }else cout << "You are not the apropriate level\n\n";
                            cout<< "Type the number of the item you want to buy\n";
                            cout<< "To exit Armor's item list,type 0\n\n";
                            cin >> Item_num;
                        }
                        break;
                    case 3:
                        for (int i = 0; i < Potions.size(); ++i)
                        {
                            cout << i+1 <<")";
                            Potions[i].print_Item();
                            cout << "\n";
                        }
                        cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";

                        cout<< "Type the number of the item you want to buy\n";
                        cout<< "To exit Potions's item list,type 0\n\n";
                        cin >> Item_num;
                        while (Item_num)
                        {
                            if (buyers[selected_hero-1]->get_lvl()>=Potions[Item_num-1].get_min_lvl()){
                                if (buyers[selected_hero-1]->get_money()>=Potions[Item_num-1].get_price())//if u can afford the item
                                {
                                    buyers[selected_hero-1]->reduce_money(Potions[Item_num-1].get_price());
                                    cout<<"Nice,you just bought " << Potions[Item_num-1].get_name();
                                    cout <<"You have " <<buyers[selected_hero-1]->get_money() <<" gold coins left!\n";
                                    buyers[selected_hero-1]->place_to_bag(&Potions[Item_num-1]);
                                    cout << "num :" << buyers[selected_hero-1]->Inventory_size() << "\n\n";
                                }else
                                {
                                    cout << "I am sorry you do not have enough gold coins\n";
                                    cout << Potions[Item_num-1].get_price()-buyers[selected_hero-1]->get_money() << " gold coins missing\n\n";
                                }
                            }else cout << "You are not the apropriate level\n\n";


                            cout<< "Type the number of the item you want to buy\n";
                            cout<< "To exit Potion's item list,type 0\n\n";
                            cin >> Item_num;
                        }
                        break;
                    case 4:
                            for (int i = 0; i < Spells.size(); ++i)
                            {
                                cout << i+1 <<")";
                                Spells[i]->print();
                                cout << "\n";
                            }
                            cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";

                            cout<< "Type the number of the item you want to buy\n";
                            cout<< "To exit Spell's item list,type 0\n\n";
                            cin >> Item_num;
                            while (Item_num)
                            {
                                if (buyers[selected_hero-1]->get_lvl()>=Spells[Item_num-1]->get_min_lvl()){
                                    if (buyers[selected_hero-1]->get_money()>=Spells[Item_num-1]->get_price())//if u can afford the item
                                    {
                                        buyers[selected_hero-1]->reduce_money(Spells[Item_num-1]->get_price());
                                        cout<<"Nice,you just bought " << Spells[Item_num-1]->get_name()<< "\n";
                                        cout <<"You have " <<buyers[selected_hero-1]->get_money() <<" gold coins left!\n\n";
                                        buyers[selected_hero-1]->learn_new_spell(Spells[Item_num-1]);
                                        //   cout << "num :" << buyers[selected_hero-1]->Inventory_size() << "\n\n";
                                    }else
                                    {
                                        cout << "I am sorry you do not have enough gold coins\n";
                                        cout << Spells[Item_num-1]->get_price()-buyers[selected_hero-1]->get_money() << " gold coins missing\n\n";
                                    }
                                }

                                cout<< "Type the number of the item you want to buy\n";
                                cout<< "To exit Spell's item list,type 0\n\n";
                                cin >> Item_num;
                            }
                            break;
                    case 5:
                            int option=1;

                            while (option){
                                cout << "0) Stop selling!\n";
                                cout << "1) Sell from inventory!\n";
                                cout << "2) Sell Spells\n";
                                cin>>option;

                                if(option==1){
                                    if (buyers[selected_hero-1]->Inventory_size()!=0)
                                    {
                                        cout << "Your inventory is: \n";
                                        buyers[selected_hero-1]->display_inventory();
                                        Item_num=1;
                                        while(Item_num and buyers[selected_hero-1]->Inventory_size()!=0)
                                        {
                                            cout<< "Type the number of the item you want to sell\n";
                                            cin>>Item_num;

                                            if (Item_num>buyers[selected_hero-1]->Inventory_size())
                                            {
                                                cout << "I am sorry you do not have that many items, choose again...\n";
                                                cin>>Item_num;
                                            }else
                                            {
                                                Item* i=buyers[selected_hero-1]->remove_from_Inv(Item_num);
                                                buyers[selected_hero-1]->increase_money(i->get_price()/2);
                                                if(buyers[selected_hero-1]->Inventory_size()!=0)
                                                {
                                                    cout << "Your inventory is: \n";
                                                    buyers[selected_hero-1]->display_inventory();
                                                }else cout << "Inventory is empty\n\n";


                                                cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";

                                            }

                                            if (buyers[selected_hero-1]->Inventory_size()!=0) cout << "Press 0 to stop selling items from Inventory \n";

                                        }
                                    }else cout << "Your Inventory is empty...\n\n";

                                } else{
                                    //sell items;
                                    int selected_sp=1;
                                    int total_spells;
                                    while (selected_sp)
                                    {
                                        if (buyers[selected_hero-1]->has_any_spells())
                                        {
                                            cout<<"Your spells are...\n";
                                            total_spells=buyers[selected_hero-1]->display_spells();
                                            cout<<"Press 0 if you want to stop selling spells!\n";

                                            cin>>selected_sp;

                                            while (selected_sp>total_spells){
                                                cout <<"You dodnt have that many spells!\n";
                                                cin>>selected_sp;
                                            }

                                            if (selected_sp)
                                            {
                                                Spell* ptr=buyers[selected_hero-1]->remove_spell(selected_sp-1);
                                                buyers[selected_hero-1]->increase_money(ptr->get_price()/2);
                                                cout<< "Your money: " << buyers[selected_hero-1]->get_money() << "\n\n";
                                            }

                                        }else {
                                            cout << "You do not have any spells right now\n";
                                            selected_sp=0;
                                        }
                                    }


                                }
                            }


                        break;
                }
                cout << "Hey " <<buyers[selected_hero-1]->get_name() << " do you want to buy/sell something more?\n";
                cout << "Type 'yes' to continue...\n";
                cout << "Type 'no' to stop...\n";
                cin >>KeepBuying;
            }
           // cout << "\033[2J\033[1;1H";


            cout << "If you want to choose an other hero to buy items ,pres yes...\n";
            cout << "To exit shop, press exit..\n";
            cin>> answer;
        }

}