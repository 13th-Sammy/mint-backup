#include<iostream>

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int d)
        {
            data=d;
            next=nullptr;
            prev=nullptr;
        }
};

class doublyLLL
{
    private:
    Node* head;

    public:
    doublyLLL() {head=nullptr;}
    doublyLLL(int d) { head=new Node(d);}

    void insertAtHead(int d)
    {
        Node* newNode=new Node(d);
        newNode->next=head;
        if(head!=nullptr)
            head->prev=newNode;
        head=newNode;
    }

    void insertAtTail(int d)
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
        newNode->prev=temp;
    }

    void deleteHead()
    {
        if(head==nullptr)
            return;
        
        Node* del=head;
        head=head->next;
        if(head!=nullptr)
            head->prev=nullptr;
        delete del;
    }

    void deleteTail()
    {
        if(head==nullptr)
            return;

        if(head->next==nullptr)
        {
            Node* del=head;
            head=head->next;
            delete del;
            return;
        }

        Node* temp=head;
        while(temp->next->next!=nullptr)
            temp=temp->next;
        delete temp->next;
        temp->next=nullptr;
    }

    void insertAtPos(int d, int pos)
    {
        if (head==nullptr) return;

        Node* newNode=new Node(d);

        if(pos==1)
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            return;
        }

        int i=1;
        Node* temp=head;
        while(i<pos-1 && temp!=nullptr)
        {
            temp=temp->next;
            i++;
        }    
        
        if(temp==nullptr)
        {
            std::cout << "Invalid Position\n";
            return;
        }

        newNode->next=temp->next;
        if(temp->next!=nullptr)
            temp->next->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
    }

    void deleteAtPos(int pos)
    {
        if(head==nullptr)
            return;

        if(pos==1)
        {
            Node* del=head;
            head=head->next;
            head->prev=nullptr;
            delete del;
            return;
        }

        int i=1;
        Node* temp=head;
        while(i<pos-1 && temp!=nullptr)
        {
            temp=temp->next;
            i++;
        }    

        if(temp==nullptr || temp->next==nullptr)
        {
            std::cout << "Invalid Position\n";
            return;
        }

        Node* del=temp->next;
        temp->next=del->next;
        if(del->next!=nullptr)
            del->next->prev=temp;
        delete del;
    }

    void reverseLL()
    {
        Node* temp=head;
        Node* back=nullptr;
        while(temp!=nullptr)
        {
            Node* nextTmp=temp->next;
            temp->next=back;
            temp->prev=nextTmp;
            back=temp;
            temp=nextTmp;
        }
        head=back;
    }

    void showList()
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            std::cout << temp->data << ' ';
            temp=temp->next;
        }
        std::cout << '\n';
    }

    ~doublyLLL()
    {
        while(head!=nullptr)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};

int main()
{
    doublyLLL List(5);
    List.insertAtHead(4);
    List.insertAtHead(1);
    List.insertAtPos(9, 4);
    List.deleteAtPos(2);
    List.insertAtTail(13);
    List.deleteHead();
    List.deleteTail();
    List.showList();
    List.reverseLL();
    List.showList();
    
    return 0;
}