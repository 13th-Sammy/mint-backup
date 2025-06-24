#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
        st.push(s[i]);

    string rev="";
    while(st.empty()!=true)
    {
        rev=rev+st.top();
        st.pop();
    }
    return rev;
}

int main()
{
    string s="Hello World";
    string rev=reverse(s);
    cout << rev << '\n';

    return 0;
}