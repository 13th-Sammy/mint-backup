#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target)
{
    int start=0,end=n-1,result=-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(target == arr[mid])
        {
            result = mid;
            end = mid-1;
        }
        else if(target > arr[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int target)
{
    int start=0,end=n-1,result=-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(target == arr[mid])
        {
            result = mid;
            start = mid+1;
        }
        else if(target > arr[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return result;
}

int countOccurrence(int arr[], int n, int target)
{
    if (firstOccurrence(arr, n, target) == -1)
        return 0;

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);
    return last-first+1;
}

int main()
{
    int arr[] = {1,2,2,2,2,4,4,4,6,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 4;
    cout << "Count - " << countOccurrence(arr, n, target) << endl;
}