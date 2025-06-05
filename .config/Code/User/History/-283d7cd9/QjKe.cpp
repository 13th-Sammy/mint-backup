#include <iostream>
#include <string>
using namespace std;
class Teacher
{
    private: 
        int salary;
    public: 
        string name, dept;
        Teacher(string name, string dept)
        {
            this->name=name;
            this->dept=dept;
        }
        void change_sal(int new_sal)
        {
            salary = new_sal;
            cout << salary;
        }    
};
int main()
{
    Teacher t1("Subhash", "CSE");
    cout << t1.name << endl << t1.dept << endl;
    t1.change_sal(10000);
    return 0;
}