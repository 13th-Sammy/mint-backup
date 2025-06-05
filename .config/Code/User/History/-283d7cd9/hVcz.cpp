#include <iostream>
Class Teacher
{
    private: 
        int salary;
    public: 
        string name, dept;
    Teacher(string name, dept)
    {
        this->name=name;
        this->dept=dept;
    }
    void change_sal(int new_sal)
        salary = new_sal;
};
int main()
{
    Teacher t1("Subhash", "CSE");
    t1.change_sal(10000);
    cout >> t1.name >> endl >> t1.dept >> endl >> t1.salary;
}