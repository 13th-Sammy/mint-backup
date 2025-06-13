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

class singlyLLL
{
    private:
        Node* head;
    
    public:
        singlyLLL() {head=nullptr;}
        singlyLLL(int d) {head=new Node(d);}

        void insertAtHead(int d) 
        {
            Node* newNode=new Node(d);
            newNode->next=head;
            head=newNode;
        }

        void insertAtTail(int d) 
        {
            Node* newNode=new Node(d);
            if (head==nullptr)
            {
                head=newNode;
                return;
            }

            Node* temp=head;
            while(temp->next!=nullptr)
                temp=temp->next;
            temp->next=newNode;    
        }

        void insertAtPos(int d, int pos) 
        {
            Node* newNode=new Node(d);
            if(pos==1)
            {
                newNode->next=head;
                head=newNode;
                return;
            }

            int i=1;
            Node* temp=head;
            while(i<pos-1 && temp != nullptr)
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
            temp->next=newNode;
        }
        
        void deleteAtPos(int pos) 
        {
            if(pos==1)
            {
                Node* temp=head;
                head=head->next;
                delete temp;
                return;
            }

            int i=1;
            Node* temp=head;
            while(i<pos-1 && temp != nullptr)
            {
                temp=temp->next;
                i++;
            }

            if(temp==nullptr || temp->next==nullptr)
            {
                std::cout << "Invalid Position\n";
                return;
            }

            Node* toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
        }

        void showList() 
        {
            Node* temp=head;
            while(temp!=nullptr)
            {
                std::cout << temp->data << '\n';
                temp=temp->next;
            }
        }
        
        ~singlyLLL()
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
    singlyLLL List(5);
    List.insertAtHead(4);
    List.insertAtHead(1);
    List.insertAtPos(9, 4);
    List.deleteAtPos(2);
    List.insertAtTail(13);
    List.showList();
    
    return 0;
}