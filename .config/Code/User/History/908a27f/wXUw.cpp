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

Node* whereCycle(Node* head)
{
    if(head==nullptr||head->next==nullptr)
        return nullptr;

    Node* slow=head;
    Node* fast=head;
    Node* entry=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        //if cycle they will meet
        if (slow==fast)
        {
            while(entry!=slow)
            {
                entry=entry->next;
                slow=slow->next;
            }
            return entry;
        }
    }
    return nullptr;
}

int main()
{
    using namespace std;

    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head,7);
    head->next->next->next=head->next->next;
    Node* cycleEntry = whereCycle(head);
    if(cycleEntry!=nullptr)
        cout << "Cycle exists at Node " << cycleEntry->data << '\n';
    else
        cout << "No Cycle exists\n";

    return 0;
}