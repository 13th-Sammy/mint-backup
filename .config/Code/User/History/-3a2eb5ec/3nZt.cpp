#include <iostream>
using namespace std;

int main()
{
    int N=5;
    int arr[]={1,2,4,5};
    //int hash[N+1] = {0};

    /*for(int i=0; i<N-1; i++)
        hash[arr[i]]++;

    for(int i=1; i<=N; i++)
    {
        if(hash[i]==0)
        {
            cout << i;
            break;
        }
    }*/

    int sumN = N*(N+1)/2;
    int sumArr = 0;
    for(int i=0; i<N-1; i++)
        sumArr+=arr[i];
    cout << sumN - sumArr;

    return 0;
}