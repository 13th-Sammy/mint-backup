#include <iostream>

int main()
{
    using namespace std;

    int arr[]={1,2,3,-2,3,-1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Kadane's but currMin for 
    // min(arr[i],currMin*arr[i]) and
    // swap currMin, currMax for -ve
    int currMin=arr[0];
    int currMax=arr[0];
    int maxProd=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]<0)
            swap(currMax, currMin);

        currMax=max(arr[i], currMax*arr[i]);
        currMin=min(arr[i], currMin*arr[i]);
        maxProd=max(maxProd, currMax);
    }
    cout << maxProd << '\n';

    return 0;
}