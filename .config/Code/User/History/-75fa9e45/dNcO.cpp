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

int josephus(Node*& head, int k)
{
    if(head==nullptr||head->next==head||k==1)
        return head->data;

    Node* temp=head;
    while(temp->next!=temp)
    {
        for(int i=1; i<k-1; i++)
            temp=temp->next;

        Node* del=temp->next;
        temp->next=temp->next->next;
        if(del==head)
            head=temp->next;
        delete del;
    }
    int survivor=temp->data;
    delete temp; // Optional delete survivor node
    return survivor; // if only care about value.
}

int main()
{
    Node* head=new Node(5);
    head->next=new Node(6);
    head->next->next=new Node(7);
    head->next->next->next=new Node(8);
    head->next->next->next->next=head;

    std::cout << "Survivor - " << josephus(head, 2) << '\n';
    return 0;
}