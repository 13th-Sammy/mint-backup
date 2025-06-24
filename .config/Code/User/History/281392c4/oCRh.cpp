#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValidParentheses(string s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='{'||s[i]=='['||s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty()) return false;

            if((st.top()=='{'&&s[i]=='}')
             ||(st.top()=='['&&s[i]==']')
             ||(st.top()=='('&&s[i]==')'))
                st.pop(); 
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s="[{({})}]";
    if(isValidParentheses(s))
        cout << "Valid\n";
    else
        cout << "Not Valid\n";
}