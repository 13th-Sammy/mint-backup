#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        bool swapped = false;
        for(int j=0; j < n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }    
        }
        if(swapped==false)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int small = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[small])
                small = j;
        }
        swap(arr[i],arr[small]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}