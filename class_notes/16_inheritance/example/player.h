#pragma once

#include<string>
#include<iostream>

class Player 
{
public:
    std::string name_;
    int level_;
    int health_;

    Player(std::string name,int level):name_(name),level_(level), health_(100){}
    virtual void print_class(){std::cout<<"Class: Player";}
    void print_level(){std::cout<<"Level: "<<level_<<" ";}

private:
    int unique_; //derived classes do not have access

};