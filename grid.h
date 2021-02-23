#ifndef OURGAME_GRID_H
#define OURGAME_GRID_H

#include "living.h"
#include <string>

class CompanyOfHeroes{
private:
    Hero* MyHeroes[3];
    int x,y;
public:
    CompanyOfHeroes(Hero* h1= nullptr ,Hero* h2= nullptr, Hero* h3= nullptr);
    ~CompanyOfHeroes(){
        delete MyHeroes[0];
        delete MyHeroes[1];
        delete MyHeroes[2];
    }
    int get_x();
    int get_y();
    void change_pos(int, int);
    Hero* get_Hero(int);
    void DisplayStats();
    bool alive();
    void print();
    int number_of_heroes();

};

class Block{
    friend class Grid;
private:
    vector<Monster*> monsters;
    CompanyOfHeroes* UserHeroes;
    std::string TypeOfBlock;

public:
    Block(std::string="Common");
    void add_monster(Monster *);
    void delete_monsters();
    void check_for_battle();
    void battle();
    void display_monsters();
    bool is_non_accessible();
    bool is_market();
};

class Grid{
private:
    friend class Block;
    Block* Map[10][10]; //
public:
    void place_to_map(CompanyOfHeroes*);
    void move_up(CompanyOfHeroes*);
    void move_down(CompanyOfHeroes*);
    void move_left(CompanyOfHeroes*);
    void move_right(CompanyOfHeroes*);
    Grid();
    void display_map();
    void populate_grid(int);
    void delete_monsters();
    vector<char> option(int , int );
    void check_battle(int, int );
    void delere_grid(){
        for (int i = 0; i <10 ; ++i) {
            for (int j = 0; j <10 ; ++j) {
                delete Map[i][j];
            }
        }
    }
};

#endif