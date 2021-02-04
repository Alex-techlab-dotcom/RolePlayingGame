#include "living.h"
class Debuff{
protected:
    Monster * target;
    int expiration_round;
public:
    Debuff(Monster *, int );
    virtual ~Debuff()=0;
    Monster *getTarget() const;

    int getExpirationRound() const;

};

class Damage_Debuff : public Debuff{
    double min_damage_debuff_amount;
    double max_damage_debuff_amount;

public:
    Damage_Debuff(Monster * m, int r,double spell_percentage);
    ~Damage_Debuff();
};

class Defence_Debuff : public Debuff{
    int defence_debuff_amount;

public:
    Defence_Debuff(Monster *,int, double);
    ~Defence_Debuff();
};

class Agility_Debuff : public Debuff{
    double agility_debuff_amount;

public:
    Agility_Debuff(Monster*, int, double);
    ~Agility_Debuff();
};
