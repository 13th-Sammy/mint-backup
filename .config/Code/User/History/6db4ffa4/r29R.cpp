#include<iostream>
using namespace std;

int main()
{
    int arr[]={12,3,4,5,7,8,5,23,43}, f=0;
    for (int i = 1; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if(arr[i-1]>arr[i]) 
        {
            cout << "Not sorted";
            f=1;
            break;
        }
    }
    if (f==0)
        cout << "Sorted";
    return 0; 
}