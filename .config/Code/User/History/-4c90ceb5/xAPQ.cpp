#include<iostream>
#include<vector>
#include<stack>

std::vector<int> nextGreater(std::vector<int> v)
{   
    using namespace std;

    vector<int> res(v.size(), -1);
    stack<int> st;
    for(int i=v.size()-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=v[i])
            st.pop();
        
        if(!st.empty())
            res[i]=st.top();

        st.push(v[i]);
    }
    return res;
}

int main()
{
    using namespace std;
    
    int arr[]={4,5,2,10,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    vector<int> v(arr, arr+n);
    vector res=nextGreater(v);
    for(int i=0; i<res.size(); i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}