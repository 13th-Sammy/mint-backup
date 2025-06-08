#include <iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    int k=2;
    int backup[k];

    //backup last k elements
    for(int i=0; i<k; i++)
        backup[i]=arr[n-k+i];

    //shift by k 
    for(int i=n-k-1; i>=0; i--)
        arr[i+k]=arr[i];

    //restore
    for(int i=0; i<k; i++)
        arr[i]=backup[i];

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}