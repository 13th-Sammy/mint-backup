#include<iostream>
using namespace std;

int fib(int N)
{
    if (N<=1)
        return N;
    return fib(N-1)+fib(N-2);
}

int main()
{
    int N;
    cout << "Enter fib count\n";
    cin >> N;
    cout << fib(N) << endl;
    return 0;
}