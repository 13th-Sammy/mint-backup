#include <iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,2,1,1,1,1,4,2,1,5,5,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    int sum=0, ans=-1;
    for (int i=0; i<n; i++)
    {
        int length=0;
        for (int j=0; j<n; j++)
        {
            sum+=j;
            if (sum==k)
            {
                length=j-i+1;
                break;
            }   
        }
        if(length>ans)
            ans=length;
    }
    cout << ans;
    return 0;
}