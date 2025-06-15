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

            Node* nextCurr=curr->next;
            curr->next=child;
            child->prev=curr;
            curr->child=nullptr;

            Node* tail=child;
            while(tail->next!=nullptr)
                tail=tail->next;
            
            tail->next=nextCurr;
            if(nextCurr!=nullptr)
                nextCurr->prev=tail;
        }
        curr=curr->next;    
    }
    return head;
}

int main()
{
    Node* head=new Node(5);
    head->next=new Node(6);
    head->next->next=new Node(7);
    head->next->child=new Node(8);
    head->next->child->next=new Node(9);
    showList(head);
    head=flatten(head);
    showList(head);
    
    return 0;
}