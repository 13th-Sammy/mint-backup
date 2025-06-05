#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v(5);
    int arr[] = {2,2,2,4,5}
    vector<int> v1 = arr;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "Enter element\n";
        cin >> (*it);
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << "Element entered - " << (*it) << endl;
    for (auto it = v1.begin(); it != v1.end(); it++)
        cout << "Element entered - " << (*it) << endl;
    return 0;
}