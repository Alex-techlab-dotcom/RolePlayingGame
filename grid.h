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
    int get_x();
    int get_y();
    void    change_pos(int, int);
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
    //DisplayStats should be implemented here; (?????)
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
    void populate_grid(int);
    void delete_monsters();
    vector<char> option(int x, int y){
        //Players movement options
        vector<char>options;
        if(y-1>=0){
            if(!Map[x][y-1]->is_non_accessible()){
                cout<<"Press D for going Down!\n";
                options.push_back('D');
            }
        }
        if(y+1<10){
            if (!Map[x][y+1]->is_non_accessible()){
                cout<<"Press U for going Up!\n";
                options.push_back('U');
            }
        }
        if (x-1>=0){
            if (!Map[x-1][y]->is_non_accessible()){
                cout<<"Press L for going Left!\n";
                options.push_back('L');
            }
        }
        if (x+1<10){
            if (!Map[x+1][y]->is_non_accessible()){
                cout<<"Press R for going Right!\n";
                options.push_back('R');
            }
        }
        if(Map[x][y]->is_market()){
            cout<<"Press M for market!\n";
            options.push_back('M');
        }

        cout<<"Press S for Display Stats!\n";
        options.push_back('S');

        cout<<"Press T for Display Map!\n";
        options.push_back('T');

        cout<<"Press Q to Quit the game!\n";
        options.push_back('Q');

        return options;

    }
    void check_battle(int x, int y){
        Map[x][y]->check_for_battle();
    }

};

#endif