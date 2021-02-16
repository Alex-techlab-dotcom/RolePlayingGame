#include "shop.h"
#include <vector>
#include <algorithm>
using namespace std;

int main() {

        Grid map;
        map.display_map();


    Warrior* w1= new Warrior("Alex");
    Paladin* p1=new Paladin("tasos");
    CompanyOfHeroes c(w1,p1);
    Shop S("weapon.txt","Armor.txt","Potions.txt","Spells.txt");
   // S.enter_shop(&c);
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
                }

                cout<<"x: " << c.get_x() << "\n";
                cout << "y: " << c.get_y() << "\n";

                map.check_battle(c.get_x(),c.get_y());


            }

}
