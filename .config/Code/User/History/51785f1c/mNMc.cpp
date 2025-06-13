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

    int i=0,j=0, k=0;
    vector<int> ans;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            if(ans.empty() || ans.back()!=arr1[i])
                ans[k++]=arr1[i++];
        }
        else 
        {
            if(ans.empty() || ans.back()!=arr2[j])
                ans[k++]=arr2[j++];
        }
    }
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}