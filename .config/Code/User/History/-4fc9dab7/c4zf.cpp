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
        newNode->next=newNode;
        head=newNode;
        return;
    }

    // Not needed if head->next=head;
    if(head->next==nullptr)
    {
        head->next=newNode;
        newNode->next=head;
        return;
    }

    Node* temp=head;
    while(temp->next!=head)
        temp=temp->next;

    newNode->next=head;
    temp->next=newNode;
}

void insertAtHead(Node*& head, int d)
{
    Node* newNode=new Node(d);
    if(head==nullptr)
    {
        newNode->next=newNode;
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->next!=head)
        temp=temp->next;

    temp->next=newNode;
    newNode->next=head;
    head=newNode;
}

void deleteTail(Node*& head)
{
    if(head==nullptr) return;

    if(head->next==head || head->next == nullptr)
    {
        delete head;
        head=nullptr;
        return;
    }

    Node* temp=head;
    while(temp->next->next!=head)
        temp=temp->next;
    // No Do While else one pass guaranteed

    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
}

void deleteHead(Node*& head)
{
    if(head==nullptr) return;

    Node* temp=head;
    while(temp->next!=head)
        temp=temp->next;

    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
    head=temp->next;
}

void insertAtPos(Node*& head, int pos, int d)
{
    Node* newNode=new Node(d);

    if(head==nullptr) return;

    if(pos==1)
    {
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
        return;
    }

    int i=1; 
    Node* temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteAtPos(Node*& head, int pos)
{
    if(head==nullptr) return;

    if(pos==1)
    {
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        Node* del=temp->next;
        temp->next=temp->next->next;
        delete del;
        head=temp->next;
        return;
    }

    int i=1;
    Node* temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
}

void reverseList(Node*& head)
{
    if(head==nullptr || head->next==head)
        return;

    Node* prev=head;
    while(prev->next!=head)
        prev=prev->next;
    
    Node* curr=head;
    do
    {
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    while(curr!=head);
    head=prev;
}

void showList(Node* head)
{
    Node* temp=head;
    do
    {
        std::cout << temp->data << ' ';
        temp=temp->next;
    } 
    while (temp!=head);
    std::cout << '\n';
}

bool checkCircular(Node* head)
{
    if(head==nullptr) return false;

    Node* temp=head->next;
    while(temp!=nullptr)
    {
        if(temp==head)
            return true;
        temp=temp->next;
    }
    return false;
}

int main()
{
    Node* head=new Node(5);
    head->next=new Node(6);
    head->next->next=new Node(7);
    head->next->next->next=new Node(8);
    head->next->next->next->next=head;
    insertAtTail(head, 9);
    insertAtHead(head, 4);
    insertAtHead(head,11);
    insertAtPos(head, 4, 12);
    showList(head);
    deleteTail(head);
    deleteHead(head);
    deleteAtPos(head, 3);
    reverseList(head);    
    showList(head);
    if(checkCircular(head))
        std::cout << "Circular Linked List\n";
    else    
        std::cout << "Not Circular Linked List";
    
    return 0;
}