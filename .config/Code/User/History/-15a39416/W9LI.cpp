#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Student
{
    private:
    string name, dept; 
    int marks1, marks2, marks3;
    public:
    Student(string n, string d, int m1, int m2, int m3)
    {
        name = n;
        dept = d;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }
    void showData()
    {
        cout << "Name - " << name << endl;
        cout << "Department - " << dept << endl;
        double avg = (marks1 + marks2 + marks3)/3.0;
        cout << "Average - " << avg << endl;
    }
};
int main()
{
    int choice; vector<Student> v;
    while(true)
    {
        cout << "1 to enter data\n2 to see all data\n3 to exit\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << "Enter name\n";
                string n; cin.ignore(); getline(cin, n);
                cout << "Enter Department\n";
                string d; getline(cin, d);
                cout << "Enter 3 marks\n";
                int m1, m2, m3;
                cin >> m1 >> m2 >> m3;
                v.push_back(Student(n,d,m1,m2,m3));
                break;
            }
            case 2:
            {
                for(int i = 0; i < v.size(); i++)
                {
                    v[i].showData();
                    cout << endl;
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Wrong Choice\n";       
        }
    }
}