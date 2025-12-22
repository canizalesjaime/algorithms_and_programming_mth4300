#pragma once

#include<string>
#include<iostream>

#include "magic_player.h"

class Wizard: public MagicPlayer
{
public:
    Wizard(std::string name, int level, int heal_level, int magic_level, 
           std::string wand, std::string magic): 
           MagicPlayer(name,level,heal_level,magic_level), wand_type_(wand),
           magic_type_(magic){}

    void print_class()override{std::cout<<"Class: Wizard ";}
    std::string get_wand(){return wand_type_;}

private:
    std::string wand_type_;
    std::string magic_type_;
};
