#include<iostream>
using namespace std;

void printName (string name, int i, int cnt)
{
    if (i > cnt)
        return;
    cout << i << ". " << name << endl;
    printName(name, i+1, cnt);
}

int main()
{
    string name; 
    int cnt;

    cout << "Enter name\n"; cin >> name;
    cout << "Enter count\n"; cin >> cnt;
    cout << endl;
    printName(name, 1, cnt);

    return 0;
}