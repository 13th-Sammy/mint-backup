#include<iostream>

class CircularQueue {
    int size, capacity, front, rear;
    int* arr;

    public:
    CircularQueue(int c) {
        capacity=c;
        arr=new int[capacity];
        front=rear=size=0;
    }

    void push(int x)
    {
        if(size==capacity) {
            std::cout << "Queue Overflow\n";
            return;
        }
        arr[rear]=x;
        rear=(rear+1)%capacity;
        size++;
    }

    void pop()
    {
        if(size==0) {
            std::cout << "Queue Underflow\n";
            return;
        }
        front=(front+1)%capacity;
        size--;
    }

    int getFront()
    {
        return arr[front];
    }

    bool empty()
    {
        return size==0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    CircularQueue q(4);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    std::cout << q.getFront() << '\n';

    q.push(50);

    q.pop();
    q.pop();

    q.push(50);
    q.push(60);
    std::cout << q.getFront() << '\n';

    while(!q.empty()) {
        std::cout << q.getFront() << ' ';
        q.pop();        
    }
    std::cout << '\n';

    return 0;
}