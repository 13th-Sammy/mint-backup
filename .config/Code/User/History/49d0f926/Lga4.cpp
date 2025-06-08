#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[]={12,3,4,5,7,8,5,23,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = INT_MIN, smax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max)
        {
            smax=max;
            max=arr[i];
        }
        else if (arr[i]>smax && arr[i] != max)
            smax=arr[i];
    }
    
    /*for (int i = 0; i < n; i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>smax && arr[i]<max)
            smax=arr[i];
    }*/

    cout << smax;
    return 0;
}