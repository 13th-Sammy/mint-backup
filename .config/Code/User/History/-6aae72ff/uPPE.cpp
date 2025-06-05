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
    while(head != 0)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    int arr[]={2,5,8,7};
    Node* head = new Node(arr[0]);
    head->next = new Node (arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    printLL();
    cout << head << endl;
    cout << head->data << endl;
    return 0;
}
