#include "grid.h"
#include <ctime>
#include <cstdlib>
#include <fstream>


//COMPANY OF HEROES
CompanyOfHeroes::CompanyOfHeroes(Hero* h1 ,Hero* h2 , Hero* h3)
{
    MyHeroes[0]=h1;
    MyHeroes[1]=h2;
    MyHeroes[2]=h3;
}

bool CompanyOfHeroes::alive()
{
    for (int i = 0; i <3 ; ++i) {
        if (MyHeroes[i]!= nullptr)
        {
            if(!MyHeroes[i]->IsAlive()) return false;
        }
    }
    return true;
}

int CompanyOfHeroes::get_x()
{
    return x;
}


int CompanyOfHeroes::get_y()
{
    return y;
}

void CompanyOfHeroes::change_pos(int x1,int y1)
{
    x=x1;
    y=y1;
}

Hero* CompanyOfHeroes::get_Hero(int n)
{
    if(MyHeroes[n-1]!= nullptr)
    {
        return MyHeroes[n-1];
    }else
        return nullptr;
}
void CompanyOfHeroes::DisplayStats()
{
    cout << "Choose one of your heroes\n";
    int hero;
    for (int i = 0; i <3 ; ++i) {
        if (MyHeroes[i]!= nullptr)
        {
            cout << i+1 << ") " << MyHeroes[i]->get_name() << endl;
        }
    }cout << "4) Exit\n";

    cin>>hero;

    while (hero!=4)
    {
        MyHeroes[hero-1]->display_stats();
        cin>> hero;
    }
    cout << "Exits...\n";
}
int CompanyOfHeroes::number_of_heroes(){
    int n=0;
    for (int i = 0; i <3 ; ++i) {
        if (MyHeroes[i]!= nullptr)n++;
    }
    return n;
}

void CompanyOfHeroes::print() {
    for (int i = 0; i < 3; ++i) {
        if (MyHeroes[i] != nullptr) {
            cout << i + 1 << ") " << MyHeroes[i]->get_name() << endl;
        }
    }
}
//BLOCK

Block::Block(std::string type){
    TypeOfBlock=type;
    UserHeroes=nullptr;
}

void Block::delete_monsters() {
    for(auto p:monsters)
        delete p;

    monsters.clear();
}
/*void Block::check_for_battle()
{
    if (!monsters.empty())//call battle function();

}*/

void Block::battle()
{
    int turn=1,selected_monster;
    while (!monsters.empty() and UserHeroes->alive() )
    {
        for (int i = 0; i <monsters.size() ; ++i) {
           // monsters[i]->print 8a mou tin ftiajeis esy mpro
        }
        UserHeroes->print();

        int choose_move;

        if (turn%2==1) {
            cout << "Heroe's turn...\n\n";
            //choose
            for (int i = 0; i < 3; ++i)
            {
                if (UserHeroes->get_Hero(i) != nullptr)
                {
                    UserHeroes->get_Hero(i)->regenerate_health();
                    if (UserHeroes->get_Hero(i)->IsAlive())
                    {
                        cout<< "1) Attack!\n";
                        cout<< "2) CastSpell!\n";
                        cout<< "3) Use Potion!\n";
                        cin>>choose_move;

                        switch (choose_move)
                        {
                            case 1:
                                cout <<"Choose monster...\n\n";
                                cin>> selected_monster;
                                UserHeroes->get_Hero(i)->attack(monsters[selected_monster-1]);
                                break;
                            case 2:
                                cout <<"Choose monster...\n\n";
                                cin>> selected_monster;
                                break;
                            case 3:
                                cout << "Choose potion...\n\n";
                                vector <Potion *>hero_pots=UserHeroes->get_Hero(i)->display_pots();
                                int chosen_pot;
                                cin>>chosen_pot;
                                while(chosen_pot<1 and chosen_pot>hero_pots.size()){
                                    cout << "Please, choose again more carefully...\n\n";
                                    cin>>chosen_pot;
                                }

                                UserHeroes->get_Hero(i)->use_pot(hero_pots[chosen_pot-1]);

                                break;
                        }

                        if (!monsters[selected_monster-1]->IsAlive())monsters.erase(monsters.begin()+selected_monster-1);

                    }

                }

            }
        }
        else {
            int target;
            for (int i = 0; i <monsters.size() ; ++i) {
                target=rand()%UserHeroes->number_of_heroes();
                while (!UserHeroes->get_Hero(target)->IsAlive()){
                    target=rand()%UserHeroes->number_of_heroes();
                }
                monsters[i]->attack(UserHeroes->get_Hero(target));
            }
        }
            turn++;
    }

        //reset stats();

}


void Block::add_monster(Monster * mptr) {
    monsters.push_back(mptr);
}

//GRID FUNCTIONS

Grid::Grid(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(
                    (i==0 and j==8) or (i==1 and j==7) or (i==2 and j==2) or (i==2 and j==4)
                    or (i==2 and j==6) or (i==2 and j==9) or (i==3 and j==1) or (i==4 and j==1)
                    or (i==4 and j==6) or (i==5 and j==3) or (i==5 and j==8) or (i==6 and j==0)
                    or (i==6 and j==7) or (i==8 and j==4) or (i==9 and j==2) or (i==9 and j==6)
                    )
                Map[i][j]=new Block("Non_accessible");


            else if( (i==0 and j==0) or (i==9 and j==9) or (i==6 and j==5))Map[i][j]=new Block("Market");
            else Map[i][j]=new Block("common");
        }
    }
}

void Grid::move_right(CompanyOfHeroes* c) {
    Map[c->get_x() + 1][c->get_y()]->UserHeroes = c;
    c->change_pos(c->get_x() - 1, c->get_y());
    //check_for_battle()
}

void Grid::move_up(CompanyOfHeroes* c){
    Map[c->get_x()][c->get_y()+1]->UserHeroes=c;
    c->change_pos(c->get_x(),c->get_y()+1);
}


void Grid::move_down(CompanyOfHeroes* c){
    Map[c->get_x()][c->get_y()-1]->UserHeroes=c;
    c->change_pos(c->get_x(),c->get_y()-1);
}

void Grid::move_left(CompanyOfHeroes* c) {
    Map[c->get_x() - 1][c->get_y()]->UserHeroes = c;
    c->change_pos(c->get_x() - 1, c->get_y());
}

void Grid::display_map() {
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(Map[i][j]->TypeOfBlock=="Market")
                std::cout<<"\u2554\u2550\u2550\u2557 ";
            else
                std::cout<<"\u250C\u2500\u2500\u2510 ";
        }
        std::cout<<std::endl;

        for(int j=0; j<10; j++){
            if(Map[i][j]->TypeOfBlock=="Market"){
                std::cout<<"\u2551";
                if(Map[i][j]->UserHeroes!=nullptr)
                    std::cout<<"\u25C0\u25B6";
                else
                    std::cout<<"  ";
                std::cout<<"\u2551 ";
            }
            else{
                std::cout<<"\u2502";
                if(Map[i][j]->TypeOfBlock=="Non_accessible")
                    std::cout<<"\u2573\u2573";
                else if(Map[i][j]->UserHeroes!=nullptr)
                    std::cout<<"\u25C0\u25B6";
                else
                    std::cout<<"  ";
                std::cout<<"\u2502 ";
            }
        }
        std::cout<<std::endl;

        for(int j=0; j<10; j++){
            if(Map[i][j]->TypeOfBlock=="Market")
                std::cout<<"\u255A\u2550\u2550\u255D ";
            else
                std::cout<<"\u2514\u2500\u2500\u2518 ";
        }
        std::cout<<std::endl;
    }
}

void Grid::delete_monsters() {
    for(int i=0; i<10; i++) {
        for (int j = 0; j < 10; j++)
            Map[i][j]->delete_monsters();
    }
}

void Grid::populate_grid(int level){

    delete_monsters();

    srand(time(nullptr));
    ifstream Names_File("Names.txt");

    for(int i=0; i<10; i++) {
        for (int j = 0; j < 10; j++) {
            if (Map[i][j]->TypeOfBlock != "Non_accessible") {
                int monster_count = rand() % 4;
                for (int k = monster_count; k > 0; k--) {
                    int monster_type = rand() % 3;

                    string name;
                    int line, curr_line=0;
                    line = rand() % 98 +1;
                    while(getline(Names_File, name)){
                        curr_line++;
                        if(curr_line==line)
                            break;
                    }

                    switch (monster_type) {
                        case 0:
                            Map[i][j]->add_monster(Dragon::Construct_Dragon(name, level));
                        case 1:
                            Map[i][j]->add_monster(Exoskeleton::Construct_Exoskeleton(name, level));
                        case 2:
                            Map[i][j]->add_monster(Spirit::Construct_Spirit(name, level));

                    }
                }
            }
        }
    }
}