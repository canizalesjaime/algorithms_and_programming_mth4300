#include<iostream>
#include "linked_list.h"
#include<limits>
#include<fstream>


void writeListToFile(LinkedList& l);


int main()
{
    // part 2
    std::ofstream out_file("names_list.txt",std::ios::app);
    if(!out_file.is_open())
    {
        std::cout<<"Write file did not open"<<std::endl;
        return 1;
    }

    std::cout<<"Enter your name: ";
    std::string my_name;
    std::getline(std::cin,my_name);
    out_file<<my_name<<std::endl;
    out_file.close();

    // part 3
    // read file and store into a linked list
    std::ifstream in_file("names_list.txt");
    if(!in_file.is_open())
    {
        std::cout<<"Read file did not open"<<std::endl;
        return 1;
    }

    LinkedList l;
    std::string f_name, l_name;
    int i = 0;
    while(in_file.peek() != EOF)
    {
        std::getline(in_file,f_name,' ');
        std::getline(in_file,l_name);
        l.insert(f_name,l_name,i);
        i++;
    }
    in_file.close();
    l.display();

    l.selectionSort();
    writeListToFile(l);

    return 0;
}


void writeListToFile(LinkedList& l)
{
    std::ofstream out_file("sorted_names.txt");
    if(!out_file.is_open())
    {
        std::cout<<"Write file did not open"<<std::endl;
        return;
    }
    
    Node* ptr=l.getHead();

    while(ptr)
    {
        out_file<<ptr->first_name<<" "<<ptr->last_name<<std::endl;
        ptr=ptr->next;
    }

    out_file.close();
}