#include <vector>
#include <iostream>
int main()
{
    vector<int> v(5);
    for (auto it = v.begin(); it != v.end(); it++)
        cin >> (*it);
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it);
    return 0;
}