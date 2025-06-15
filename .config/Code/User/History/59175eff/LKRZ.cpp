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

void showList(Node* head)
{
    while(head!=nullptr)
    {
        std::cout << head->data << " ";
        head=head->next;
    }
    std::cout << '\n';
}

bool isPalindrome(Node* head)
{
    bool isPal=true;
    
    // Find mid element
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    // Reverse from slow to end;
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

    // Check head to mid and mid to end
    Node* t1=head;
    Node* t2=slow;
    while(t1!=nullptr && t2!=nullptr)
    {
        if(t1->data!=t2->data)
        {
            isPal=false;
            break;
        }  
        t1=t1->next;
        t2=t2->next;
    }

    // Re-reverse second half for restoration
    Node* prev2=nullptr;
    Node* temp2=slow;
    while(temp2!=nullptr)
    {
        Node* next=temp2->next;
        temp2->next=prev2;
        prev2=temp2;
        temp2=next;
    }
    slow=prev2;

    // Don't do this, the list was 
    // never split. This creates a cycle.
    // (We are using Node* not Node*&)
    /*while(head->next!=nullptr)
        head=head->next;
    head->next=slow;*/
    
    return isPal;
}

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 5);
    if(isPalindrome(head)) 
        std::cout << "Palindrome\n";
    else
        std::cout << "Not Palindrome\n";
    showList(head);

    return 0;
}