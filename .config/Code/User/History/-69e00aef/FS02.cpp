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

Node* mergeLists(Node* head1, Node* head2)
{
    Node* dummy=new Node(0);
    Node* current=dummy;

    while(head1!=nullptr && head2!=nullptr)
    {
        if(head1->data<=head2->data)
        {
            current->next=new Node(head1->data);
            head1=head1->next;
        }
        else
        {
            current->next=new Node(head2->data);
            head2=head2->next;
        }
        current=current->next;
    }

    while(head1!=nullptr)
    {
        current->next=new Node(head1->data);
        current=current->next;
        head1=head1->next;
    }
    while(head2!=nullptr)
    {
        current->next=new Node(head2->data);
        current=current->next;
        head2=head2->next;
    }

    return dummy->next;
}

int main()
{
    Node* head1=new Node(5);
    insertAtTail(head1, 6);
    insertAtTail(head1, 7);

    Node* head2=new Node(3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 8);

    Node* merged=mergeLists(head1, head2);
    showList(merged);

    return 0;
}