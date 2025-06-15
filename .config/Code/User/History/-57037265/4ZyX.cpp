#include<iostream>

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;
    Node(int d)
    {
        data=d;
        next=nullptr;
        prev=nullptr;
        child=nullptr;
    }
};

void showList(Node* head)
{
    while(head!=nullptr)
    {
        std::cout << head->data << ' ';
        head=head->next;
    }
    std::cout << '\n';
}

Node* flatten(Node* head)
{
    if(head==nullptr) return head;

    Node* curr=head;
    while(curr!=nullptr)
    {
        if(curr->child!=nullptr)
        {
            Node* child=flatten(curr->child);

            Node* next=curr->next;
            curr->next=child;
            child->prev=curr;
            curr->child=nullptr;

            Node* tail=child;
            while(tail!=nullptr)
                tail=tail->next;
            
            tail->next=next;
            if(next!=nullptr)
                next->prev=tail;
        }
        curr=curr->next;    
    }
    return head;
}

int main()
{
    Node* head=new Node(5);
    Node* temp=head;
    temp->next=new Node(6);
    temp->next->next=new Node(7);
    temp->next->child=new Node(8);
    temp->next->child->next=new Node(9);
    showList(head);
    head=flatten(head);
    showList(head);
    
    return 0;
}