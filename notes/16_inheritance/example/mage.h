#pragma once

#include<string>
#include<iostream>

#include "magic_player.h"

class Mage: public MagicPlayer
{
public:
    Mage(std::string name, int level, int heal_level, int magic_level,
         std::string book, std::string dark_magic): 
         MagicPlayer(name,level,heal_level,magic_level), 
         book_type_(book), dark_magic_type_(dark_magic){}

    void print_class()override{std::cout<<"Class: Mage ";}
    void print_name(){std::cout<<name_<<" ";}

private:
    std::string book_type_;
    std::string dark_magic_type_;

};