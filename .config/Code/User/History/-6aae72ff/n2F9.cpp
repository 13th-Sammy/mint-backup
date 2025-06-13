#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node (int d, Node* n)
    {
        this->data = d;
        this->next = n;
    }
    Node (int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};
void printLL(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
void deleteTail(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        ;
    Node* temp = head;
    while(temp->next->next != nullptr) //2nd last->last->nullptr
        temp = temp->next; //temp is now 2nd last element
    delete temp->next;
    temp->next = nullptr;
}
int main()
{
    int arr[]={2,5,8,7};
    Node* head = new Node(arr[0]); //head(2)->nullptr
    head->next = new Node (arr[1]); //head->next(5)->nullptr
    head->next->next = new Node(arr[2]); //head->next->next(8)->nullptr
    head->next->next->next = new Node(arr[3]); // head->next->next->next(7)->nullptr
    deleteTail(head);
    printLL(head);
    return 0;
}