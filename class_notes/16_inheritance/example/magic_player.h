#pragma once

#include<string>
#include<iostream>

#include "player.h"

// if private, Player data not accesible for derived classes of Magic Player,
// if protected, Player data only accessible to derived classed in derived class
class MagicPlayer: protected Player 
{
public:
    MagicPlayer(std::string name, int level, int healer_level, int magic_level): 
    Player(name,level), healer_level_(healer_level), magic_level_(magic_level){}
    void print_class()override{std::cout<<"Class: Magic Player ";}
    int healer_level_;
    int magic_level_;
};