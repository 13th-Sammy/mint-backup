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
        newNode->next=newNode;
        head=newNode;
        return;
    }

    // Not needed if head->next=head;
    if(head->next==nullptr)
    {
        head->next=newNode;
        newNode->next=head;
        return;
    }

    Node* temp=head;
    do
        temp=temp->next;
    while(temp->next!=head);

    newNode->next=head;
    temp->next=newNode;
}

void insertAtHead(Node*& head, int d)
{
    Node* newNode=new Node(d);
    if(head==nullptr)
    {
        newNode->next=newNode;
        head=newNode;
        return;
    }

    Node* temp=head;
    do
        temp=temp->next;
    while(temp->next!=head);

    temp->next=newNode;
    newNode->next=head;
    head=newNode;
}

void deleteHead(Node*& head)
{
    if(head==nullptr) return;

    Node* temp=head;
    do
        temp=temp->next;
    while(temp->next!=head);

    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
    head=temp->next;
}

void showList(Node* head)
{
    Node* temp=head;
    do
    {
        std::cout << temp->data << ' ';
        temp=temp->next;
    } 
    while (temp!=head);
    std::cout << '\n';
}

int main()
{
    Node* head=new Node(5);
    head->next=new Node(6);
    head->next->next=new Node(7);
    head->next->next->next=new Node(8);
    head->next->next->next->next=head;
    insertAtTail(head, 9);
    insertAtHead(head, 4);
    insertAtHead(head,11);
    showList(head);
    deleteHead(head);    
    showList(head);
    
    return 0;
}