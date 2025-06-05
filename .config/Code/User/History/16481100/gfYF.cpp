#include<iostream>
#include<string>
using namespace std;
class Teacher
{
    public:
    string name, dept; int* id;
    Teacher(string n, d; int idty) // init constructor
    {
        name = n;
        dept = d;
        id = new int;
        *id = idty;
    }
    Teacher(Teacher &obj) // copy constructor
    {
        this->name = obj.name;
        this->dept = obj.dept;
        id = new int; // make separate addr for copying
        *(this->id) = *(obj.id); //only add value to separate addr
    }
};
int main()
{
    Teacher t1("Sam", "ChE", 1234567);
    Teacher t2(t1);
    cout << t1.id << endl << t2.id;
    return 0;
}