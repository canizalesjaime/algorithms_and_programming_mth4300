#pragma once

#include<string>
#include<iostream>

#include "player.h"

class Knight : public Player
{
public:
    Knight(std::string name, int level, std::string lance, std::string horse): 
    Player(name,level), lance_type_(lance), horse_name_(horse){}

    void print_class()override{std::cout<<"Class: Knight ";}
    void train_lance()
    {
        health_=health_-20;
        level_=level_+1;
    }

private:
    std::string lance_type_;
    std::string horse_name_;

};