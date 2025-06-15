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
    
    showList(head);
    
    return 0;
}