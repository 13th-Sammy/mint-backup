#include<iostream>
#include<string>
using namespace std;
class Teacher
{
    public:
    string name, dept; int* id;
    Teacher(string n, string d, int idty) // init constructor
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
    ~Teacher()
    {
        delete id; // de-allocate id space that was allocated at runtime
    }
};
int main()
{
    Teacher t1("Sam", "ChE", 1234567);
    Teacher t2(t1);
    cout << *t1.id << endl << *t2.id << endl;
    *t1.id = *t1.id +10;
    cout << *t1.id << endl << *t2.id << endl;
    return 0;
}