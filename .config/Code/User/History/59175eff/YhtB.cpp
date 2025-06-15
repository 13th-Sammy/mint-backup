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

bool isPalindrome(Node* head)
{
    //find mid element
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    //reverse from slow to end;
    Node* prev=nullptr;
    Node* temp=slow;
    while(temp!=nullptr)
    {
        Node* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    slow=prev;

    //check head to mid and mid to end
    Node* t1=head;
    Node* t2=slow;
    while(t1!=nullptr && t2!=nullptr)
    {
        if(t1->data!=t2->data)
            return false;
        t1=t1->next;
        t2=t2->next;
    }
    return true;
}

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 5);
    if(isPalindrome(head)) //calling this splits the list in half
        std::cout << "Palindrome\n";
    else
        std::cout << "Not Palindrome\n";

    return 0;
}
