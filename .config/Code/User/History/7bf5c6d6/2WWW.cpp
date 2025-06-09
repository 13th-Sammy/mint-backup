#include <iostream>
#include <unordered_map>

int main()
{
    using namespace std;

    int arr[]={1,2,2,3,1,4,5,-1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=4;

    /*for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                cout << i << " " << j;
                cout << "\n";
            }    
        }
    }*/

    unordered_map<int, int> map;
    for(int i=0; i<n; i++)
    {
        int complement=target-arr[i];

        if(map.find(complement)!=map.end())
        {
            cout << map[complement] << " " << i << "\n";
            break;
        }

        map[arr[i]]=i;
    }

    return 0;
}