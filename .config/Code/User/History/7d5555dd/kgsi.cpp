#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int top=s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(top);

}

void reverse(stack<int> &s)
{
    if(s.empty()) return;

    int top=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, top);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << '\n';
    reverse(st);
    cout << st.top() << '\n';
    
    return 0;
}