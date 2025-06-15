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

void deleteNthEnd(Node*& head, int n)
{
    Node* temp=head;
    int l=0;
    while(temp!=nullptr)
    {
        l++;
        temp=temp->next;
    }
    
    int pos=l-n+1;
    if(pos==1)
    {
        Node* toDel=head;
        head=head->next;
        delete toDel;
        return;
    }

    Node* temp2=head;
    int i=1;
    while(i<pos-1 && temp2!=nullptr)
    {
        temp2=temp2->next;
        i++;
    }    

    if(temp2==nullptr || temp2->next==nullptr)
    {
        std::cout << "Invalid Position\n";
        return;
    } 

    Node* toDel=temp2->next;
    temp2->next=temp2->next->next;
    delete toDel;
}

int main()
{
    Node* head=new Node(5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    deleteNthEnd(head,2);
    showList(head);
    
    return 0;
}