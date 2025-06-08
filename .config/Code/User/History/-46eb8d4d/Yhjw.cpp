#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
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

void rcBubbleSort(int arr[], int n)
{
    if (n==1)
        return;
        
    bool swapped = false;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            swapped=true;
        }   
    }
    if (swapped == false)
        return ;
    rcBubbleSort(arr, n-1);
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

void rcInsertionSort(int arr[], int i, int n)
{
    if (i==n)
        return ;
    
    int j = i;
    while(j>0 && arr[j-1]>arr[j])
    {
        swap(arr[j-1],arr[j]);
        j--;
    }
    rcInsertionSort(arr, i+1, n);
}

void merge(int arr[], int low, int mid, int high)
{
    int n1=mid-low+1,n2=high-mid,L[n1],R[n2];
    for (int i = 0; i < n1; i++)
        L[i]=arr[low+i];
    for (int i = 0; i < n2; i++)
        R[i]=arr[mid+1+i];
    
    int i=0,j=0,k=low;
    while (i < n1 && j < n2)
    {
        if (L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int low, int high)
{
    if(low>=high)
        return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int partition(int arr[], int low, int high)
{
    int i=low-1;

    for(int j = low; j < high; j++)
    {
        if(arr[j]<arr[high])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low>=high)
        return;
    
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
}

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    //insertionSort(arr, n);
    //rcBubbleSort(arr, n);
    //rcInsertionSort(arr, 1, n);
    //mergeSort(arr, 0, n-1);
    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}