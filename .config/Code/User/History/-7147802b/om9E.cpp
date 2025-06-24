#include<iostream>
#include<queue>

void reverse(std::queue<int> &q)
{
    if(q.empty()) return;
    int front=q.front();
    q.pop();
    reverse(q);
    q.push(front);
}

int main()
{
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << q.front() << '\n';
    reverse(q);
    std::cout << q.front() << '\n';

    return 0;
}