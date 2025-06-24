#include<iostream>

class Queue
{
    int* arr;
    int front, rear, size, capacity;

    public:    
    Queue(int c)
    {
        capacity=c;
        arr=new int[capacity];
        front=rear=size=0;
    }

    void enqueue(int x)
    {
        if(size==capacity)
        {
            std::cout << "Queue Overflow\n";
            return;
        }
        arr[rear]=x;
        rear++;
        size++;
    }

    void dequeue()
    {
        if(size==0)
        {
            std::cout << "Queue Underflow\n";
            return;
        }
        front++;
        size--;
    }

    int getFront()
    {
        if(size==0) return -1;
        return arr[front];
    }

    bool isEmpty()
    {
        return size==0;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    using namespace std;

    Queue q(5);
    for(int i=1; i<=5; i++)
        q.enqueue(i);
    q.dequeue();
    cout << q.getFront() << '\n';

    return 0;
}