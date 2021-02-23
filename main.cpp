#include "shop.h"
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    Hero * characters[3];
    characters[0]=nullptr;
    characters[1]=nullptr;
    characters[2]=nullptr;

    int choice;
    string schoice;
    string n;

    cout<<"Hello player lets create your characters."<<endl;
    int i=0;
    do{
        cout<<"Select type of hero:"<<endl;
        cout<<"1) Warrior"<<endl;
        cout<<"2) Sorcerer"<<endl;
        cout<<"3) Paladin"<<endl;

        cin>>choice;
        while(choice<1 or choice>3){
            cout<<"Your input must be a number from 1-3, please enter again."<<endl;
            cin>>choice;
        }

        cout<<"What will your hero's name be?"<<endl;
        cin>>n;

        if(choice==1)
            characters[i]= new Warrior(n);
        else if(choice==2)
            characters[i]= new Sorcerer(n);
        else characters[i]= new Paladin(n);

        if(i!=3)
            cout<<"Do you wish to create another hero? (YES/NO)"<<endl;
            cin>>schoice;
            while(schoice!="YES" and schoice!="NO"){
                cout<<"Your input must be YES or NO, please enter again."<<endl;
                cin>>schoice;
            }

            if(schoice=="NO")
                break;
            else
                i++;

    }while(i<3);

    cout<<"Hero creation is complete, the game will begin soon!"<<endl;

    Grid map;



    CompanyOfHeroes c(characters[0],characters[1], characters[2]);
    Shop S;

    map.place_to_map(&c);
    map.display_map();

    char input;
            while(input!='Q'){
                vector<char>moves=map.option(c.get_x(),c.get_y());

                cin>>input;

                while ( !(find(moves.begin(),moves.end(),input)!=moves.end()) ){
                    moves=map.option(c.get_x(),c.get_y());
                    cin>>input;
                }


                switch (input) {
                    case 'U':
                       map.move_up(&c);
                        break;

                    case 'D':
                        map.move_down(&c);
                        break;

                    case 'R':
                        map.move_right(&c);
                        break;

                    case 'L':
                        map.move_left(&c);
                        break;

                    case 'T':
                        //display map
                        map.display_map();
                        break;

                    case'S':
                        c.DisplayStats();
                        break;

                    case 'M':
                        S.enter_shop(&c);
                        break;
                    case 'E':
                        for (int i = 0; i <3 ; ++i) {
                            if (c.get_Hero(i)!= nullptr){
                                c.get_Hero(i)->equip();
                            }
                        }
                        break;
                    case 'P':{

                    }
                        cout << "Choose hero to use potion!\n";
                        int sh=1;
                        while (sh){
                            cout<<"0) exit...\n";
                            for (int i = 0; i <c.number_of_heroes() ; ++i) {
                                if (c.get_Hero(i)!= nullptr){
                                    cout<< i+1<<") " <<c.get_Hero(i)->get_name()<<"\n";
                                }
                            }
                            cin>>sh;
                            if (sh==0)break;
                            while (sh>c.number_of_heroes())cin>>sh;

                            cout << "Choose potion...\n\n";
                            vector<Potion *> hero_pots = c.get_Hero(sh-1)->display_pots();
                            if (hero_pots.size()!=0){
                                int chosen_pot;
                                cin >> chosen_pot;
                                while (chosen_pot < 1 or chosen_pot > hero_pots.size()) {
                                    cout << "Please, choose again more carefully...\n\n";
                                    cin >> chosen_pot;
                                }

                                c.get_Hero(sh)->use_pot(hero_pots[chosen_pot - 1]);
                            }else cout << "You havent any pots!\n\n";

                        }
                        break;
                }
                map.check_battle(c.get_x(),c.get_y());
                for (int i = 0; i < 3; ++i) {
                    if (c.get_Hero(i)!= nullptr){
                        if (c.get_Hero(i)->get_lvl()==3){
                            map.populate_grid(2);
                        }else if (c.get_Hero(i)->get_lvl()==4){
                            map.populate_grid(3);
                        }
                    }
                }

                cout << "Quiting game...\n";


            }
            map.delere_grid();
            S.delete_shop();
}
