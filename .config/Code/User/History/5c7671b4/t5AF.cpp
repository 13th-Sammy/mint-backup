#include <iostream>
using namespace std;

void sumToN(int N, int sum)
{
    if (N<1)
    {
        cout << sum << endl;
        return ;
    }
    sumToN(N-1, sum+N);
}

int main()
{
    int N;
    cout << "Sum till ?\n"; cin >> N;
    sumToN(N,0);
}