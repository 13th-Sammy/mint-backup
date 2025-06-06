#include <iostream>
using namespace std;

void print1toN(int i, int N)
{
    if (i > N)
        return;
    cout << i;
    print1toN(i++, N);
}

int main()
{
    int N;
    cout << "Enter N\n"; cin >> N;
    print1toN(1, N);
}