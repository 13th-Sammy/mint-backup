#include<iostream>

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        data=d;
        next=nullptr;
    }
};

class Stack
{
    Node* top;

    public:
    Stack()
    {
        top=nullptr;
    }

    void push(int x)
    {
        Node* newNode=new Node(x);
        newNode->next=top;
        top=newNode;
    }

    void pop()
    {
        if (top==nullptr)
        {
            std::cout << "Stack Underflow\n";
        }
        Node* del=top;
        top=top->next;
        delete del;
    }

    int peek()
    {
        if (top==nullptr) return -1;
        return top->data;
    }

    bool isEmpty()
    {
        return top==nullptr;
    }

    ~Stack()
    {
        while(top!=nullptr)
        {
            Node* del=top;
            top=top->next;
            delete del;
        }
    }
};

int main()
{
    using namespace std;

    Stack s;
    for(int i=1; i<=5; i++)
        s.push(i);
    cout << s.peek() << '\n';
    
    return 0;
}