#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    string name;
    int age;
    Person(string n, int a) {
        name = n;
        age = a;
    }
};
class Student : public Person {
public:
    int rollno;
    Student(string n, int a, int rno) : Person(n, a) {
        rollno = rno;
    }
};
int main() {
    Student s("Sam", 21, 3654822);
    cout << s.name << endl;
    return 0;
}