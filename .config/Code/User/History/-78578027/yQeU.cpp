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

void showList(Node* head)
{
    while(head!=nullptr)
    {
        std::cout << head->data << " ";
        head=head->next;
    }
    std::cout << '\n';
}

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

void deleteMid(Node*& head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        // prev=slow; could have just done this
        // and deleted prev->next
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node* temp=head;
    if(temp==nullptr)
    {
        std::cout << "Invalid Position\n";
        return;
    }

    if(temp==slow)
    {
        Node* toDel=head;
        head=head->next;
        delete toDel;
        return;
    }

    while(temp->next!=slow)
        temp=temp->next;

    Node* toDel=temp->next;
    temp->next=temp->next->next;
    delete toDel;
}

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    deleteMid(head);
    showList(head);

    return 0;
}