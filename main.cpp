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
    map.display_map();

    CompanyOfHeroes c(characters[0],characters[1], characters[2]);
    Shop S("weapon.txt","Armor.txt","Potions.txt","Spells.txt");
   map.place_to_map(&c);
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
                }

                cout<<"x: " << c.get_x() << "\n";
                cout << "y: " << c.get_y() << "\n";
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




            }

}
