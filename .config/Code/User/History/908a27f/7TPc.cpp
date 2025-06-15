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

int detectCycle(Node* head)
{
    if(head==nullptr||head->next==nullptr)
        return false;

    Node* slow=head;
    Node* fast=head;
    int cyclePos=-1;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        //if cycle they will meet
        if (slow==fast)
        {
            while(slow!=nullptr)
            {
                slow=slow->next;
                cyclePos++;
            }
            break;
        }
    }
    return cyclePos;
}

int main()
{
    using namespace std;

    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head,7);
    head->next->next=head->next;
    int cyclePos = detectCycle(head);
    if(cyclePos!=-1)
        cout << "Cycle exists at position " << cyclePos << '\n';
    else
        cout << "No Cycle exists\n";

    return 0;
}