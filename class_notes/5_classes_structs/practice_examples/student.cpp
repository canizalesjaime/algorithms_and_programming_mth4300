#include<iostream>

using namespace std;

class Student 
{
public:
    string name;
    int grade;
    void display() 
    {
        cout << name << " has a grade of " << grade << endl;
    }
};

int main()
{
    Student s;
    s.name = "albert";
    s.grade=99;
    s.display();

    Student* s_ptr=new Student;
    //s_ptr=&s;//or point it to s
    s_ptr->name = "john";
    s_ptr->grade=87;
    s_ptr->display();


    return 0;
}