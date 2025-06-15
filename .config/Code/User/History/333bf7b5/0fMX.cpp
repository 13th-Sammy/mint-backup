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

void reorderList(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    Node* prev=nullptr;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* curr=prev->next;
    Node* back=nullptr;
    while(curr!=nullptr)
    {
        Node* next=curr->next;
        curr->next=back;
        back=curr;
        curr=next;
    }
    prev->next=nullptr;

    Node* first=head;
    Node* second=back;
    while(second!=nullptr) // second smaller if odd number of elements
    {
        Node* tmp1=first->next;
        Node* tmp2=second->next;
        first->next=second;
        second->next=tmp1;
        first=tmp1;
        second=tmp2;
    }
}

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);

    reorderList(head);
    showList(head);

    return 0;
}