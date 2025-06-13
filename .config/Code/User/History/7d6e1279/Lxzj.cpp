#include <iostream>

int main()
{
    using namespace std;

    int arr[]={1,1,1,1,1,1,1,1,1,2,2,2,3,3,3,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    int count=0;
    int candidate=-1;
    for (int i=0; i<n; i++)
    {
        if(count==0)
            candidate=arr[i];

        if(candidate==arr[i])
            count++;
        else
            count--;
    }

    // Verify
    count=0;
    for (int i=0; i<n; i++)
    {
        if(arr[i]==candidate)
            count++;
    }
    if (count>n/2)
        cout << "Majority Element - " << candidate;
    else    
        cout << "No Majority Element";

    return 0;
}