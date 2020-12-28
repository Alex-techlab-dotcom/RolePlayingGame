#include "grid.h"


//COMPANY OF HEROES

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



            if( (i==0 and j==0) or (i==9 and j==9) or (i==6 and j==5))Map[i][j]=new Block("Market");

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