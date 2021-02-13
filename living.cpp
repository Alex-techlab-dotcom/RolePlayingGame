#include "living.h"
#include <cmath>
#include "deduff.h"
//LIVING
Living::Living(string lname,int lvl, double hp, double agil):name(lname)
{
  //  name=lname;
    level=lvl;
    max_healthPower=hp;
    current_hp=max_healthPower;
    agility=agil;
}

string Living::get_name(){
    return name;
}


//WARRIOR

Warrior::Warrior(string w_name):Hero(std::move(w_name), 200, 0.25, 75, 0.05)
{
    cout << "A new warrior named as " << name << " has been created\n";
}

void Warrior::level_up()
{
    level++;
    cout << "The prideful warrior " << name << " has now reached level " << level << "\n";
    strength+=40;
    agility+=0.07;
    dexterity+=0.04;
}

//PALADIN

Paladin::Paladin(string p_name):Hero(p_name, 200, 0.1, 75, 0.2)
{
    cout << "A new paladin named as " << name << " has been created\n";
}

void Paladin::level_up()
{
    level++;
    cout << "The glorious paladin " << name << " has now reached level " << level << "\n";
    strength+=40;
    agility+=0.04;
    dexterity+=0.07;
}

//SORCERER
Sorcerer::Sorcerer(string s_name):Hero(s_name, 200, 0.25, 50, 0.2)
{
    cout << "A new sorcerer named as " << name << " has been created\n";
}

void Sorcerer::level_up()
{
    level++;
    cout << "The legendary sorcerer " << name << " has now reached level " << level << "\n";
    strength+=30;
    agility+=0.07;
    dexterity+=0.07;
}

//HERO

Hero::Hero(const string& h_name, double hp, double agil, int str, double dext):Living(h_name, 1, hp, agil)
{
    exp=0;
    magicPower=100;
    money=1200;
    for(int i=0; i<4; i++)
        Abilities[i]=nullptr;
}

bool Living::IsAlive()
{
    if (current_hp==0)return false;

    return true;
}

void Living::setAgility(double a) {
    Living::agility = a;
}

void Hero::lose_money()
{
    // after each defeated battle the hero looses half of his money!
    money=money/2;
}

void Hero::regenerate()
{
    current_hp+= max_healthPower*0.2;
    current_magic_power+=(int )(current_magic_power*0.2);
    //we dont want to regenerate more hp than the hero initially has!
    if (current_hp>max_healthPower)current_hp=max_healthPower;
    if (current_magic_power>magicPower)current_magic_power=magicPower;
}
void Hero::revive() {
    current_hp=max_healthPower/2;
}
int Hero::get_money()
{
    return money;
}

void Hero::reduce_money(int money_to_subtract)
{
    money-=money_to_subtract;
}

void Hero::increase_money(int n)
{
    money+=n;
}

void Hero::place_to_bag(Item* i)
{
    Inventory.push_back(i);
}

void Hero::learn_new_spell(Spell* s)
{
    for (int i = 0; i <4 ; ++i) {
        if (Abilities[i] == nullptr)
        {
            Abilities[i]=s;
            break;
        }
    }
}

int Hero::Inventory_size()
{
    return Inventory.size();
}

vector<Item*> Hero::get_Inventory()
{
    return Inventory;
}

void Hero::display_inventory()
{
    for (int i = 0; i <Inventory_size() ; ++i) {
        cout << i+1 << ")" << "\n";
        Inventory[i]->print_Item();
        cout << "\n\n";
    }
}

Item* Hero::remove_from_Inv(int n)
{
    Item *ptr=Inventory[n-1];
    Inventory.erase(Inventory.begin()+n-1);
    return ptr;
}

void Hero::display_stats(){
    cout << name << endl;
    cout << level << endl;
    switch (level) {
        case 1:{
            cout << "XP: " << exp << "/"<< LEVEL_TWO<<endl;
            break;
        }
        case 2:{
            cout << "XP: " << exp << "/"<< LEVEL_THREE<<endl;
            break;
        }
        case 3:{
            cout << "XP: " << exp << "/"<< LEVEL_FOUR<<endl;
            break;
        }
        case 4:{
            cout << "XP: " << exp << "/"<< LEVEL_FIVE<<endl;
            break;
        }
    }
    cout << "HP : " << current_hp << "/" << max_healthPower <<endl;
    cout << "Mana: " << current_magic_power<< "/" << magicPower<<  endl;
    cout << "Agility: " << agility << endl;
    cout << "Dexterity: " << dexterity << endl;
}

void Hero::wear(Item* ptr)
{
    if (dynamic_cast<Weapon*>(ptr)!= nullptr)//this means ptr is Weapon type pointer;
    {

            if (dynamic_cast<Weapon*>(ptr)->two_hands())
            {
                //two hands means both left and right hand pointers points to the same weapon
                    if (B.right_hand== nullptr)B.right_hand=dynamic_cast<Weapon*>(ptr);
                    else{
                        place_to_bag(B.right_hand);
                        B.right_hand=dynamic_cast<Weapon*>(ptr);
                    }

                    if (B.left_hand== nullptr)B.left_hand=dynamic_cast<Weapon*>(ptr);
                    else{
                        place_to_bag(B.left_hand);
                        B.left_hand=dynamic_cast<Weapon*>(ptr);
                    }
            } else{
                //One hand weapon
                //first checks if the equiped weapon is two haned;
                        if (B.left_hand->two_hands())
                        {
                            place_to_bag(B.left_hand);//put the old weapon to bug
                            B.right_hand= nullptr;// the other hand is now free
                            B.left_hand=(Weapon*)ptr;
                                    //dynamic_cast<Weapon*>(ptr);
                        }else{

                                if (B.right_hand== nullptr)B.right_hand=dynamic_cast<Weapon*>(ptr);
                                else if(B.left_hand== nullptr)B.left_hand=dynamic_cast<Weapon*>(ptr);
                                else{
                                    //Both hands already have weapons
                                    cout <<"Choose which weapon you want to replace...\n\n";

                                    cout<<"Left:\n";
                                    B.left_hand->print_Item();

                                    cout <<"Right: \n";
                                    B.right_hand->print_Item();

                                    string hand;
                                    cin>>hand;

                                        if (hand=="Left")
                                        {
                                            place_to_bag(B.left_hand);
                                            B.left_hand=B.left_hand=dynamic_cast<Weapon*>(ptr);
                                        }else{
                                            place_to_bag(B.right_hand);
                                            B.right_hand=dynamic_cast<Weapon*>(ptr);
                                        }
                                }

                         }
            }

    }else {//it is armor type;
        if (B.chest== nullptr)
        {
            B.chest=dynamic_cast<Armor*>(ptr);
        }else{
            place_to_bag(B.chest);//we put it to bag so we can wear the other item;
            B.chest=dynamic_cast<Armor*>(ptr);
        }
    }
}

void Hero::equip()
{
 if (Inventory_size()){
     display_inventory();

     int item_num;

     cout << "Choose one item to equip...\n";
     cout <<"Press 0 to exit\n";
     cin>>item_num;
     while (item_num)
     {
         wear(remove_from_Inv(item_num));
         cin>>item_num;
         display_inventory();
     }
 }else cout << "You havent any items yet...\n\n";


}

void Hero::lose_life(int damage)
{
    double defence=0;
    if (B.chest!= nullptr){//we check if the hero is armed
        defence=B.chest->get_damage_reduction();
    }
    damage=damage-damage*defence;
    current_hp=current_hp-damage;
    if(current_hp<0)current_hp=0;
}

void Monster::lose_life(int damage)
{
    double pain=damage-defence;
    current_hp=current_hp-pain;
    if(current_hp<0)current_hp=0;
}

void Hero::attack(Monster *m1)
{
    int random_number=rand()%100+1;
    double d=m1->get_agility()*100;
    if ((double )random_number>d){
        int dmg;
        if (B.left_hand==B.right_hand and B.left_hand!= nullptr)
        {
            //we have two hand weapon
            m1->lose_life(B.left_hand->get_damage());
        } else
        {
            if (B.left_hand!= nullptr)m1->lose_life(B.left_hand->get_damage());
            if(B.right_hand!= nullptr)m1->lose_life(B.right_hand->get_damage());
        }
    }

}

void Hero::use_pot(Potion* potion)
{
    potion->buff_stats(current_hp,current_magic_power,agility,strength,dexterity);
    for (int i = 0; i <Inventory_size() ; ++i) {
        if (potion==Inventory[i])Inventory.erase(Inventory.begin()+i);
    }
}

vector <Potion *> Hero::display_pots(){
    vector <Potion *> pots;
    for(auto& i : Inventory){
        if(dynamic_cast<Potion *>(i)!=nullptr)
            pots.push_back((Potion *) i);
    }

    for(int i=0; i<pots.size(); i++){
        cout<<"## "<<i+1<<" ##"<<endl;
        pots[i]->print_use();
        cout<<endl;
    }

    return pots;
}

int Hero::display_spells() {
    int k=0;
    for(int i=0; i<4; i++){
        if(Abilities[i]!=nullptr){
            k++;
            cout<<k<<") ";
            Abilities[i]->battle_display();
            cout<<endl;
        }
    }
    return k;
}

Debuff* Hero::use_spell(int spell, Monster* target, int turn){
    int random=rand()%100+1;
    double d=target->get_agility()*100;
    if((double)random>d){
        int hit=rand()%(Abilities[spell]->getMaxDamage() -Abilities[spell]->getMinDamage()+1) + Abilities[spell]->getMinDamage();
        target->lose_life(hit);
        if(target->IsAlive()){
            if(dynamic_cast<IceSpell *> (Abilities[spell])!=nullptr){
                Debuff * db;
               // Dragon M("alex",4,1.0,1.0,2,2,2);
               db = new Damage_Debuff(target, turn+2*Abilities[spell]->getRounds(), Abilities[spell]->getDebuff());
                target->setMinDamage(floor(target->getMinDamage()-target->getMinDamage()*Abilities[spell]->getDebuff()));
                target->setMaxDamage(floor(target->getMaxDamage()-target->getMaxDamage()*Abilities[spell]->getDebuff()));
                return db;
            }
            else if(dynamic_cast<FireSpell *> (Abilities[spell])!=nullptr){
                Debuff * db;
               // Damage_Debuff b(target, turn+2*Abilities[spell]->getRounds(), Abilities[spell]->getDebuff());
                db = new Defence_Debuff(target, turn+2*Abilities[spell]->getRounds(), Abilities[spell]->getDebuff());
                target->setDefence(floor(target->getDefence()-target->getDefence()*Abilities[spell]->getDebuff()));
                return db;
            }
            else{
                Debuff *db;
                db = new Agility_Debuff(target, turn+2*Abilities[spell]->getRounds(), Abilities[spell]->getDebuff());
                target->setAgility(target->get_agility()-target->get_agility()*Abilities[spell]->getDebuff());
                return db;

            }
        }
        else return nullptr;
    }
    else
        return nullptr;
}
bool Hero:: has_any_spells()
{
    if(Abilities[0]== nullptr)return false;
    return true;
}

Spell* Hero::remove_spell(int spell_num)
{
    Spell *ptr=Abilities[spell_num];
    if(spell_num!=3){
        for (int i = spell_num; i < 3; ++i) {
            Abilities[i]=Abilities[i+1];
            Abilities[i+1]= nullptr;
        }
    }
    return ptr;
}

int Living::get_lvl() {
    return level;
}

void Hero::gain_exp(int experience) {

    switch (level) {

        case 1:{
            if(exp+experience<=LEVEL_TWO){
                level++;//Becomes level 2!
                exp=exp+experience-1000;
            }else exp+=experience;
            break;
        }
        case 2:{
            if (exp + experience<=LEVEL_THREE){
                level++;//Becomes level 3!
                exp=exp+experience-2000;
            }else exp+=experience;
            break;
        }
        case 3:{
            if (exp+experience<=LEVEL_FOUR){
                level++;//Becomes level 4!
                exp=exp+experience-3000;
            } else exp+=experience;
            break;
        }
        case 4:{
            if (exp+experience<=LEVEL_FIVE){
                level++;//Becomes level 5!
                exp=exp+experience-4000;
            }else exp+=experience;
            break;
        }case 5:{
            exp=4000;
            break;
        }
    }


}

//MONSTER
Monster::Monster(string m_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Living(m_name, lvl, hp, agil)
{
    min_damage=min_dmg;
    max_damage=max_dmg;
    defence=def;
}

void Monster::display_stats(){
    cout << "Name: " << name;
    cout << " ## Level: " << level;
    cout << " ## HP : " << current_hp << "/" << max_healthPower;
    cout << " ## Attack: " << min_damage<< " - "<<max_damage;
    cout << " ## Defence: " << defence;
}

void Monster::attack(Hero *hero)
{
    int hit=rand()%(max_damage -min_damage+1) + min_damage;
    // we generate a number between max_damage and min_damage;
    double dodge=hero->get_agility()*100;
    int random_num=rand()%100+1;
    if ((double )random_num>dodge)hero->lose_life(hit);
}

int Monster::getMinDamage() const {
    return min_damage;
}

int Monster::getMaxDamage() const {
    return max_damage;
}

int Monster::getDefence() const {
    return defence;
}

void Monster::setMinDamage(int minDamage) {
    min_damage = minDamage;
}

void Monster::setMaxDamage(int maxDamage) {
    max_damage = maxDamage;
}

void Monster::setDefence(int defence) {
    Monster::defence = defence;
}
void Monster::regenerate() {
    current_hp+= max_healthPower*0.35;
       //we dont want to regenerate more hp than the hero initially has!
    if (current_hp>max_healthPower)current_hp=max_healthPower;
}



//DRAGON
Dragon::Dragon(string d_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Monster(d_name, lvl, hp, agil, min_dmg, max_dmg, def)
{
}

Dragon * Dragon::Construct_Dragon(string name, int lvl) {
    switch(lvl){
        case 3:
            return  new Dragon(name, 3, 1000, 0.2, 170, 220, 150);
        case 2:
             return  new Dragon(name, 2, 450, 0.1, 100, 140, 50);
        default:
             return new Dragon(name, 1, 200, 0, 50, 80, 0);
    }
}

//EXOSKELETON
Exoskeleton::Exoskeleton(string e_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Monster(e_name, lvl, hp, agil, min_dmg, max_dmg, def)
{
}

Exoskeleton * Exoskeleton::Construct_Exoskeleton(string name, int lvl)
{
    switch(lvl){
    case 3:
        return new Exoskeleton(name, 3, 1000, 0.2, 135, 180, 180);
    case 2:
        return new Exoskeleton(name, 2, 450, 0.1, 60, 110, 100);
    default:
        return new Exoskeleton(name, 1, 200, 0, 30, 50, 60);
    }
}

//SPIRIT
Spirit::Spirit(string s_name, int lvl, double hp, double agil, int min_dmg, int max_dmg, int def):Monster(s_name, lvl, hp, agil, min_dmg, max_dmg, def)
{
}

Spirit * Spirit::Construct_Spirit(string name, int lvl)
{
    switch(lvl){
    case 3:
        return new Spirit(name, 3, 1000, 0.5, 135, 180, 150);
    case 2:
        return new Spirit(name, 2, 450, 0.3, 60, 110, 50);
    default:
        return new Spirit(name, 1, 200, 0.2, 30, 50, 0);
    }
}