#include "string"
#include <iostream>
using namespace std;

class Living{
    private:
        string name;
        int level;
        int healthpower;
    public:
        Living(string onoma,int lvl=1,int hp=500):name(onoma),level(lvl),healthpower(hp)
        {
            //the constructor of living beings
        }
};

class Hero: public Living{
    private:
        int mana;
        int money;
protected:
        int strenght;
        int agility;
        int dexterity;
    public:
        Hero(string name):Living(name)
        {
            mana=100;
            money=100;
        }
};

class Warrior: public Hero{
    public:
        Warrior(string name):Hero(name)
        {
            strenght=100;
            agility=80;
            dexterity=30;
            cout << "A new warrior named as " << name << " has been created\n";
        }
};