#include<iostream>
#include<stack>

class Queue 
{
    std::stack<int> input, output;
    
    public:
    void transfer()
    {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
    }
    
    void push(int x)
    {
        input.push(x);
    }

    void pop()
    {
        transfer();
        output.pop();
    }

    int front()
    {
        transfer();
        return output.top();
    }

    bool empty()
    {
        return input.empty()&&output.empty();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.front() << '\n';
}