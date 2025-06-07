#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1], R[n2];

    for (int i = 0; i<n1; i++)
        L[i]=arr[low+i];
    for (int i = 0; i<n2; i++)
        R[i]=arr[mid+i+1];

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else   
            arr[k++]=R[j++];
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int low, int high)
{
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}