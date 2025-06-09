#include<iostream>

int main()
{
    using namespace std;

    int arr[]={1,1,1,2,2,2,0,0,1,2,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int low=0, mid=0, high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
            mid++;
        else
        {   swap(arr[mid],arr[high]);
            high--;
        }
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}