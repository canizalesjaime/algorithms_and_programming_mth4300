#include<iostream>
#include<string>

#include "player.h"
#include "knight.h"
#include "warrior.h"
#include "wizard.h"
#include "archer.h"
#include "mage.h"


void knight_test();
void warrior_test();
void magic_test();
void archer_test();


int main()
{
    knight_test();
    //warrior_test();
    //magic_test();
    //archer_test();
    return 0;
}


// shows off public inheritance with virtual function
///////////////////////////////////////////////////////////////////////////////
void knight_test()
{
    Knight* k1 = new Knight("Louie", 1, "Wooden Lance", "Pony");
    k1->print_class();
    std::cout<<", ";
    k1->train_lance();
    k1->print_level();
    std::cout<<", ";
    //Note: Line below is allowed
    std::cout<<k1->name_;
    std::cout<<std::endl;

    Player* p1=new Player("Max",1);
    p1->print_class();
    std::cout<<std::endl;

    //polymorphism 
    Player* p2 = k1;
    p2->print_class();
    std::cout<<", ";
    p2=p1;
    p1->print_class();
    std::cout<<std::endl;


    delete k1,p1,p2;
}


// shows off the private use of inheritance
///////////////////////////////////////////////////////////////////////////////
void warrior_test()
{
    Warrior* w1 = new Warrior("Axel", 5, "Silver Axe", "Wooden Shield");
    w1->print_class(); 
    //illegal because everything inherited is set to private
    //w1->print_level();
    std::cout<<", ";
    w1->print_level_warrior();
    std::cout<<std::endl;

    delete w1;
}

//shows off protected use of inheritance
///////////////////////////////////////////////////////////////////////////////
void magic_test()
{
    Mage* m1=new Mage("Al", 2, 2, 3, "Intro to Sorcery", "Will o Wisp");
    m1->print_class();
    std::cout<<", ";  
    //std::cout<<m1->name_; //not allowed
    m1->print_name(); //allowed if protected
    std::cout<<std::endl;

    Wizard* w1=new Wizard("Edward", 2, 3, 2, "Wooden Wand", "Heal Partner");
    w1->print_class();
    std::cout<<", ";
    std::cout<<w1->get_wand()<<std::endl;

    delete m1,w1;
}


//shows off multiple inheritance
///////////////////////////////////////////////////////////////////////////////
void archer_test()
{
    Archer* a1= new Archer("Claude", 5, 100, "Land of Fire", "Iron Bow");
    a1->print_class();
    std::cout<<", ";
    a1->sell_weapon();
    a1->print_stats();
    delete a1;
}
