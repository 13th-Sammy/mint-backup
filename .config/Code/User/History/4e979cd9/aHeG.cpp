#include<iostream>
#include<queue>

class Stack
{
    std::queue<int> q;

    public:
    void push(int x)
    {
        q.push(x);
        int size=q.size();
        size--;
        while(size>0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    void pop()
    {
        q.pop();
    }

    int top()
    {
        return q.front();
    } 

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << '\n';
    
    return 0;
}