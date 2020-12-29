#include "grid.h"


//COMPANY OF HEROES
CompanyOfHeroes::CompanyOfHeroes(Hero* h1 ,Hero* h2 , Hero* h3)
{
    MyHeroes[0]=h1;
    MyHeroes[1]=h2;
    MyHeroes[2]=h2;
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

//BLOCK

Block::Block(std::string type){
    TypeOfBlock=type;
    UserHeroes=nullptr;
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