#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[]={1,2,3,2,1,1,1,1,4,2,1,5,5,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    unordered_map<int,int> prefixIndex;
    int sum=0, maxLen=0;
    for (int i=0; i<n; i++)
    {
        sum += arr[i];
        if(sum==k)
            maxLen=i+1;

        if(prefixIndex.find(sum-k)!=prefixIndex.end())
        {
            int len = i-prefixIndex[sum-k];
            maxLen=max(len, maxLen);
        }

        if(prefixIndex.find(sum)==prefixIndex.end())
            prefixIndex[sum]=i;
    }
    cout << maxLen;
    
    /*int ans=-1;
    for (int i=0; i<n; i++)
    {
        int length=0, sum=0;
        for (int j=i; j<n; j++)
        {
            sum+=arr[j];
            if (sum==k)
            {
                length=j-i+1;
                break;
            }   
        }
        if(length>ans)
            ans=length;
    }
    cout << ans;*/

    return 0;
}