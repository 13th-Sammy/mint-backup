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
int main()
{
    int arr[]={2,5,8,7};
    Node* y = new Node(arr[0]);
    cout << y << endl;
    cout << y->data << endl;
    return 0;
}
