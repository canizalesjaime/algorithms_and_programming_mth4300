#pragma once

#include<string>
#include<iostream>

#include "player.h"

class Warrior: private Player
{
public:
    Warrior(std::string name, int level, std::string axe, std::string shield): 
    Player(name,level), axe_type_(axe), shield_type_(shield){}
    void print_class()override{std::cout<<"Class: Warrior ";}
    void print_level_warrior(){print_level();}

private:
    std::string axe_type_;
    std::string shield_type_;

};