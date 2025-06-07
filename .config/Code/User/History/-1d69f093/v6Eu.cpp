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
