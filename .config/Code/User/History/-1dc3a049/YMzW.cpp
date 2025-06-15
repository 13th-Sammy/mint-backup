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

Node* getIntersection(Node* head1, Node* head2)
{
    if(head1==nullptr || head2==nullptr)
        return nullptr;

    Node* a=head1;
    Node* b=head2;

    while(a!=b)
    {
        a = (a==nullptr) ? head2 : a->next;
        b = (b==nullptr) ? head1 : b->next;
    }

    return a;
}

int main()
{
    Node* head1=new Node(5);
    insertAtTail(head1, 6);
    insertAtTail(head1, 7);

    Node* head2=new Node(3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 8);
    head2->next->next->next=head1->next->next;
    insertAtTail(head1, 9);
    insertAtTail(head2, 10);
    
    showList(head1);
    showList(head2);

    Node* intersect=getIntersection(head1, head2);
    if(intersect==nullptr)
        std::cout << "No Intersect\n";
    else    
        std::cout << "Intersect at Node - " << intersect << "\nData at Node - " << intersect->data << '\n';

    return 0;
}