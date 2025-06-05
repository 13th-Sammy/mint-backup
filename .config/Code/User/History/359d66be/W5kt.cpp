#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v(5);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "Enter element\n";
        cin >> (*it);
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << "Vector - " << (*it) << endl;
    return 0;
}