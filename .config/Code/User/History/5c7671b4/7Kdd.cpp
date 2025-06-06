#include <iostream>
using namespace std;

void sumToN(int i, int N)
{
    static int s = 0;
    s = s+i;
    if (i == N)
    {
        cout << s << endl;
        return;
    }   
    sumToN(i+1, N);
}

int main()
{
    int N;
    cout << "Sum till ?\n"; cin >> N;
    sumToN(1, N);
}