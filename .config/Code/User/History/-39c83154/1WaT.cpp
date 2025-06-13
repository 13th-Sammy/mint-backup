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

        void deleteHead()
        {
            Node* temp=head;
            head=head->next;
            delete temp;
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

        void deleteTail()
        {
            if(head==nullptr)
                return;
    
            if(head->next==nullptr)
            {
                delete head;
                head=nullptr;
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

        int countLL()
        {
            Node* temp=head;
            int c=0;
            while(temp!=nullptr)
            {
                c++;
                temp=temp->next;
            }
            return c;
        }

        int searchLL(int d)
        {
            Node* temp=head;
            int i=1;
            while(temp!=nullptr)
            {
                if(temp->data==d)
                    return i;
                temp=temp->next;
                i++;
            }
            return -1;
        }

        void reverseLL()
        {
            Node* prev=nullptr;
            Node* temp=head;
            while(temp!=nullptr)
            {
                Node* next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
            }
            head=prev;
        }

        void showList() 
        {
            Node* temp=head;
            while(temp!=nullptr)
            {
                std::cout << temp->data << '\n'; //segfault here
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
    List.deleteHead();
    List.deleteTail();
    List.showList();
    int count=List.countLL();
    std::cout << "Count - " << count << '\n';
    int pos=List.searchLL(5);
    if(pos==-1)
        std::cout << "Not Found\n";
    else
        std::cout << "Found at - " << pos << '\n';
    List.reverseLL();
    List.showList();
    
    return 0;
}