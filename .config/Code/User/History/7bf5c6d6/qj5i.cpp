#include <iostream>

int main()
{
    using namespace std;

    int arr[]={1,2,2,3,1,4,5,-1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=4;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                cout << i << " " << j;
            }
        }
        cout << "\n";
    }

    return 0;
}