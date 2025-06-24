#include<iostream>

class Node {
    public:
    int data;
    Node* next; 
    Node* prev;
    Node(int d) {
        data=d;
        next=nullptr;
        prev=nullptr;
    }
};

class deQueue {
    Node* front;
    Node* rear;

    public:
    deQueue() {front=rear=nullptr;}

    void pushFront(int x) {
        Node* newNode=new Node(x);
        if(front==nullptr) {
            front=rear=newNode;
            return;
        }
        newNode->next=front;
        front->prev=newNode;
        front=newNode;
    }

    void pushBack(int x) {
        Node* newNode=new Node(x);
        if(rear==nullptr) {
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        newNode->prev=rear;
        rear=newNode;
    }

    void popFront() {
        if(front==nullptr) return;
        Node* del=front;
        front=front->next;
        if(front)
            front->prev=nullptr;
        else
            rear=nullptr;
        delete del;
    }

    void popBack() {
        if(rear==nullptr) return;
        Node* del=rear;
        rear=rear->prev;
        if(!rear)
            front=nullptr;
        rear->next=nullptr;
        delete del;
    }

    int getFront() {
        return front->data;
    }

    int getBack() {
        return rear->data;
    }

    bool empty() {
        return front==nullptr;
    }

    ~deQueue() {
        while(front!=nullptr) {
            Node* del=front;
            front=front->next;
            delete del;
        }
    }
};

int main() {
    deQueue dq;
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushBack(25);

    std::cout << dq.getFront() << '\n' << dq.getBack() << '\n';
    dq.popFront();
    dq.popBack();
    std::cout << dq.getFront() << '\n' << dq.getBack() << '\n';

    if(dq.empty())
        std::cout << "Empty\n";
    else    
        std::cout << "Not Empty\n";

    return 0;
}