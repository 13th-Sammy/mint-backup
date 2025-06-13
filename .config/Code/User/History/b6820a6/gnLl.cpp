#include<iostream>
#include<unordered_map>
#include<vector>

int main()
{
    using namespace std;

    int arr1[]={1,1,2,3,4,4};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={3,4,5,6,6,7,8,9};
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    unordered_map<int, int> visited;
    for(int i=0; i<n1; i++)
        visited[arr1[i]]==1;

    for(int i=0; i<n2; i++)
    {
        if(visited[arr2[i]]==1)
            cout << arr2[i] << " ";
        visited[arr2[i]]==0;
    }
    
    int i=0,j=0;
    vector<int> ans;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else
        {
            if(ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << '\n';

    return 0;
}