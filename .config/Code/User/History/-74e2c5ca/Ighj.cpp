#include<iostream>
using namespace std;

void printName (string name, int cnt)
{
    cout << name << endl;
    cnt--;
    if (cnt == 0)
        return;
    printName(name, cnt);
}

int main()
{
    string name; 
    int cnt;

    cout << "Enter name\n"; cin >> name;
    cout << "Enter count\n"; cin >> cnt;
    cout << endl;
    printName(name, cnt);

    return 0;
}