#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
    string name; int age;
    Person(string n, int a)
    {
        name=n;
        age=a;
    }
};
class Student:public Person{
    public: 
    int rollno; string n; int a;
    Student(int rno):Person(n, a)
    {
        rollno=rno;
    }
};
int main(){
    Student s(2155002, "Sam", 21);
    cout << s.rollno << endl;
    return 0;
}