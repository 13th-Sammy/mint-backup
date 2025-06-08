#include <iostream>
using namespace std;

int main()
{
    int arr[]={1,1,0,2,1,1,1,1,3,1,1,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int c=0, max1=0;
    for (int i=0; i<n; i++)
    {
        /*while(arr[i]==1)
        {
            c++;
            i++;
        }
        if (c>max1)
            max1=c;
        c = 0;*/

        if(arr[i]==1)
            c++;
        else
            c=0;
        
        if (c>max1)
            max1=c;
    }
    cout << "Max consecutive 1s - " << max1;

    return 0;
}