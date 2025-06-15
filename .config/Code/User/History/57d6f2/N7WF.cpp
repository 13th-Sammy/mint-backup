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

Node* mergeLL(Node* l, Node* r)
{
    Node* dummy=new Node(0);
    Node* current=dummy;
    while(l!=nullptr && r!=nullptr)
    {
        if(l->data<=r->data)
        {
            current->next=l;
            l=l->next;
        }
        else
        {
            current->next=r;
            r=r->next;
        }
        current=current->next;
    }
    if(l!=nullptr)
        current->next=l;
    else if(r!=nullptr)
        current->next=r;

    return dummy->next;
}

Node* mergeSortLL(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* slow=head;
    Node* fast=head;
    Node* midPrev=nullptr;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        midPrev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node* right=midPrev->next;
    midPrev->next=nullptr;

    Node* leftSorted=mergeSortLL(head);
    Node* rightSorted=mergeSortLL(right);
    Node* merged=mergeLL(leftSorted, rightSorted);
    return merged; // with updated head 
}

int main()
{
    Node* head=new Node(6);
    insertAtTail(head, 5);
    insertAtTail(head, 10);
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    insertAtTail(head, 8);

    head=mergeSortLL(head); // if you don,t assign new head to head,
    showList(head);         // showList() will print incomplete list

    return 0;
}