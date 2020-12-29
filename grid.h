#include "living.h"
#include <string>

class CompanyOfHeroes{
private:
    Hero* MyHeroes[3];
    int x,y;
public:
    int get_x();
    int get_y();
    void change_pos(int, int);
};

class Block{
    friend class Grid;
private:
    vector<Monster*> monsters;
    CompanyOfHeroes* UserHeroes;
    std::string TypeOfBlock;

public:
    Block(std::string="Common");

};

class Grid{
private:
    friend class Block;
    Block* Map[10][10]; //
public:
    void move_up(CompanyOfHeroes*);
    void move_down(CompanyOfHeroes*);

    void move_left(CompanyOfHeroes*);
    void move_right(CompanyOfHeroes*);
    Grid();

    void display_map();
};
