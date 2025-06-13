#include<iostream>

int main()
{
    using namespace std;

    int arr[]={1,2,-3,2,4,-4,4,2,5,6,4,-2,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int currSum=arr[0], maxSum=arr[0];
    for (int i=1; i<n; i++)
    {
        currSum=max(arr[i],currSum+arr[i]);
        maxSum=max(maxSum, currSum);
    }

    cout << maxSum;
    
    return 0;
}