#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> minSt;

    public:
    void push(int x)
    {
        st.push(x);
        if(minSt.empty()||x<=minSt.top())
            minSt.push(x);
        else    
            minSt.push(minSt.top());
    }
    void pop()
    {
        if(!st.empty())
        {
            st.pop();
            minSt.pop();
        }
    }
    int top()
    {
        return st.top();
    }
    int getMin()
    {
        return minSt.top();
    }
    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    using namespace std;

    MinStack st;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(6);
    cout << st.getMin() << '\n';

    return 0;
}