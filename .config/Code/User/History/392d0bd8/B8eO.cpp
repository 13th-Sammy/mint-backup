#include<iostream>

class Stack
{
    int size;
    int* arr;
    int top;

    public:

    Stack(int s)
    {
        size=s;
        arr=new int[size];
        top=-1;
    }

    void push(int x)
    {
        if(top==size-1)
        {
            std::cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop()
    {
        if(top==-1)
        {
            std::cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if(top==-1) return -1;
        return arr[top];
    }

    bool isEmpty()
    {
        return top==-1;
    }

    ~Stack()
    {
        delete arr;
    }
};

int main()
{
    using namespace std;

    Stack s(5);
    for(int i=1; i<=5; i++)
        s.push(i);
    cout << s.peek() << '\n';
    
    return 0;
}