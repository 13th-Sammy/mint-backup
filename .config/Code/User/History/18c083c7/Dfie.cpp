#include <iostream>
using namespace std;

int main()
{
    int arr[]={12,3,4,5,7,8,5,23,43}, max=-1;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if (arr[i]>max)
            max=arr[i];
    }
    cout << max << endl;
    return 0;
}
