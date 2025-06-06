#include <iostream>
using namespace std;

void sumToN(int N, int sum)
{
    sum = sum + N;
    N--;
    if (N == 0)
    {
        cout << sum << endl;
        return ;
    }
    sumToN(N, sum);
}

int main()
{
    int N;
    cout << "Sum till ?\n"; cin >> N;
    sumToN(N,0);
}