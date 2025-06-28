#include<iostream>
using namespace std;

void heapifyDown(int arr[], int i, int n)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && arr[left]<arr[smallest])
        smallest=left;
    if(right<n && arr[right]<arr[smallest])
        smallest=right;

    if(smallest!=i)
    {
        swap(arr[i], arr[smallest]);
        heapifyDown(arr, smallest, n);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i=n/2-1; i>=0; i--)
        heapifyDown(arr, i, n);
}

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    buildHeap(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}