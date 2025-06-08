#include<iostream>
using namespace std;

int main()
{
    int arr[]={0,0,0,1,2,3,4,3,2,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    int j=0, c=0, ans[n];
    for (int i=0; i<n; i++)
    {
        if(arr[i] != 0)
        {
            ans[j]=arr[i];
            j++;
        }    
        else
            c++;
    }
    
    for (int i=0; i<c; i++)
    {
        ans[j]=0;
        j++;
    }

    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}