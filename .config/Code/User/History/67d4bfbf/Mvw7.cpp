#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int arr[]={1,1,2,3,4,4,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int> freq;
    vector<int> ans;
    for (int i=0; i<n; i++)
    {   
        freq[arr[i]]++;
        if (freq[arr[i]]==1)
            ans.push_back(arr[i]);
    }
    
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}