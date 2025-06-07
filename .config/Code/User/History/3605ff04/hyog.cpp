#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int start = 0, end = n-1, result = -1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==target)
        {
            result = mid;
            break;
        }    
        else if (arr[mid]>target)
            end = mid-1;
        else
            start = mid+1;
    }
    return result;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    int target = 6;
    int result = binarySearch(arr, n, target);
    cout << "Index (-1 if not found) = " << result << endl;
}