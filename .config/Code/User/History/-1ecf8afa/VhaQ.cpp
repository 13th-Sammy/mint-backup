#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[] = {1,1,1,2,2,3,4,5,5,6,4,3,6,6,7,8,5,8,8,4};

    unordered_map<int, int> mp;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        mp[arr[i]]++;

    cout << "Frequency of ?\n";
    int n; cin >> n;
    cout << "Frequency is - " << mp[n] << endl;

    int max = -1, maxEl;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if (mp[arr[i]] >= max)
        {
            max = mp[arr[i]];
            maxEl = arr[i];
        }    
    }
    cout << "Element with highest frequency - " << maxEl << endl;

    return 0;
}