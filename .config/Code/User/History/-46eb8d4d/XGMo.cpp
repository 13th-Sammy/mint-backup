#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    

    for(int i=0, i<n; i++)
        cout << arr[i] << " ";
}
