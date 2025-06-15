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

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    Node* temp1=head;
    Node* rev = new Node(temp1->data);
    temp1=temp1->next;
    Node* temp2=rev;
    while(temp1 != nullptr)
    {
        temp2->next=new Node(temp1->data);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    Node* temp3=rev;
    Node* prev=nullptr;
    while(temp3 != nullptr)
    {
        Node* next=temp3->next;
        temp3->next=prev;
        prev=temp3;
        temp3=next;
    }
    rev=prev;

    int flag=0;
    while(head!=nullptr)
    {
        if(head->data!=rev->data)
            flag=1;
        head=head->next;
        rev=rev->next;
    }   

    if(flag==0)
        std::cout << "Palindrome\n";
    else    
        std::cout << "Not Palindrome\n";

    return 0;
}