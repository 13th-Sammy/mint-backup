#include <iostream>
using namespace std;

int main()
{
    int N=5;
    int arr[]={1,2,4,5};
    int hash[N] = {0};

    for(int i=0; i<N-1; i++)
        hash[arr[i]]++;

    for(int i=1; i<=N; i++)
    {
        if(hash[i]==0)
        {
            cout << i;
            break;
        }
    }

    return 0;
}