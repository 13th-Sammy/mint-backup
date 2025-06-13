#include<iostream>

int main()
{
    using namespace std;

    int arr[]={1,2,-3,2,4,-4,4,2,5,6,4,-2,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Kadane's, max(arr[i],currSUm)
    // max(maxLen, currSum)
    int currSum=arr[0], maxSum=arr[0];
    int start=0, end;
    for (int i=1; i<n; i++)
    {
        if(arr[i]>currSum+arr[i])
        {
            currSum=arr[i];
            start=i;
        }
        else
            currSum+=arr[i];

        if(currSum>maxSum)
        {
            maxSum=currSum;
            end=i;
        }
    }

    for(int i=start; i<=end; i++)
        cout << arr[i] << " ";
    cout << '\n' << maxSum << '\n';
    
    return 0;
}