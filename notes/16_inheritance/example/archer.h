#pragma once

#include<string>
#include<iostream>

#include "player.h"
#include "merchant.h"

class Archer: public Player, public Merchant
{
public:
    Archer(std::string name, int level, int gold, std::string territory,
           std::string bow): 
           Player(name,level), Merchant(gold, territory),
           bow_type_(bow){}

    void print_class(){std::cout<<"Class: Archer ";}
    void sell_weapon()override
    {
        gold_=gold_+20;
        inventory_--;
    }

private:
    std::string bow_type_;

};