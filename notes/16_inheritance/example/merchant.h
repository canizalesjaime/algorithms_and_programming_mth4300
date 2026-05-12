#pragma once 

#include<string>
#include<iostream>


class Merchant
{
public:
    Merchant(int gold, std::string territory): gold_(gold), 
    territory_(territory),inventory_(10){}
    void print_stats(){std::cout<<territory_<<", Gold: "<<gold_
                       <<", Inventory: "<<inventory_<<std::endl;}
                       
    virtual void sell_weapon()=0;// pure virtual function

protected:
    int gold_;
    std::string territory_;
    int inventory_;

};