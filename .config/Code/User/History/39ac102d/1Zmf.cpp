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

Node* rcReverseLL(Node*& head)
{
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* newHead=rcReverseLL(head->next);

    head->next->next=head;
    head->next=nullptr;

    return newHead;
}

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    Node* rev=rcReverseLL(head);
    showList(rev);

    return 0;
}