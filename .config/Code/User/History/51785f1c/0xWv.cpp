#include<iostream>
#include<set>
#include<vector>

int main()
{
    using namespace std;

    int arr1[]={1,1,2,3,4,4};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={3,4,5,6,6,7,8,9};
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    // Set stores only unique so store 
    // everything in set for union
    set<int> set;

    for(int i=0; i<n1; i++)
        set.insert(arr1[i]);
    
    for(int i=0; i<n2; i++)
        set.insert(arr2[i]);
    
    for(auto it=set.begin(); it!=set.end(); it++)
        cout << *it << " ";
    cout << '\n';
    
    // Merge Sort type merging, but include
    // result.back!=arr[i] before pushing arr[i]
    // to avoid duplicates
    /*int i=0,j=0;
    vector<int> ans;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            if(ans.empty() || ans.back()!=arr1[i])
                ans.push_back(arr1[i]);
            i++;    
        }
        else if(arr1[i]>arr2[j])
        {
            if(ans.empty() || ans.back()!=arr2[j])
                ans.push_back(arr2[j]);
            j++;    
        }
        else
        {
            if(ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i<n1)
    {
        if(ans.empty() || ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        i++;
    }
    while (j<n2)
    {
        if(ans.empty() || ans.back() != arr2[j])
            ans.push_back(arr2[j]);
        j++;
    }

    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << '\n';*/

    return 0;
}