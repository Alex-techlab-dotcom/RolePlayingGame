#include "deduff.h"
#include "cmath"

//DEBUFF

Debuff::Debuff(Monster * m, int r) {
    target = m;
    expiration_round=r;
}
Debuff::~Debuff()
{

}

Monster *Debuff::getTarget() const {
    return target;
}

int Debuff::getExpirationRound() const {
    return expiration_round;
}

//DAMAGE DEBUFF

Damage_Debuff::Damage_Debuff(Monster *m, int r, double spell_percentage) : Debuff(m,r) {
    min_damage_debuff_amount= floor(target->getMinDamage() * spell_percentage);
    max_damage_debuff_amount= floor(target->getMaxDamage() *spell_percentage);
}

Damage_Debuff::~Damage_Debuff(){
    target->setMinDamage(target->getMinDamage()+min_damage_debuff_amount);
    target->setMaxDamage(target->getMaxDamage()+max_damage_debuff_amount);
}

//DEFENCE DEBUFF

Defence_Debuff::Defence_Debuff(Monster *m, int r, double spell_percentage):Debuff(m,r) {
    defence_debuff_amount= floor(target->getDefence()*spell_percentage);
}

Defence_Debuff::~Defence_Debuff(){
    target->setDefence(target->getDefence()+defence_debuff_amount);
}

//AGILITY DEBUFF

Agility_Debuff::Agility_Debuff(Monster *m, int r, double spell_percentage): Debuff(m,r){
    agility_debuff_amount=target->get_agility()*spell_percentage;
}

Agility_Debuff::~Agility_Debuff(){
    target->setAgility(target->get_agility()+agility_debuff_amount);
}