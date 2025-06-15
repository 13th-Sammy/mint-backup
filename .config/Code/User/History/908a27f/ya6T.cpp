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

void insertAtTail(Node*& head, int d)
{
    Node* newNode=new Node(d);
    if(head==nullptr)
    {
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next=newNode;
}

bool detectCycle(Node* head)
{
    if(head==nullptr||head->next==nullptr)
        return false;

    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        //if cycle they will meet
        if (slow==fast)
            return true;
    }
    return false;
}

int main()
{
    using namespace std;

    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head,7);
    head->next->next=head->next;
    if(detectCycle(head))
        cout << "Cycle exists\n";
    else
        cout << "No Cycle exists\n";

    return 0;
}