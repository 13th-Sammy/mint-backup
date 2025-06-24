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

class Queue
{
    Node* front;
    Node* rear;

    public:
    Queue()
    {
        front=rear=nullptr;
    }

    void enqueue(int x)
    {
        Node* newNode=new Node(x);
        if(rear==nullptr)
        {
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }

    void dequeue()
    {
        if(front==nullptr)
        {
            std::cout << "Queue Underflow\n";
            return;
        }
        Node* del=front;
        front=front->next;
        if(front==nullptr)
            rear=nullptr;
        delete del;
    }

    int getFront()
    {
        if(front==nullptr) return -1;
        return front->data;
    }

    bool isEmpty()
    {
        return front==nullptr;
    }

    ~Queue()
    {
        while(front!=nullptr)
        {
            Node* del=front;
            front=front->next;
            delete del;
        }
    }
};

int main()
{
    using namespace std;

    Queue q;
    for(int i=1; i<=5; i++)
        q.enqueue(i);
    q.dequeue();
    cout << q.getFront() << '\n';

    return 0;
}