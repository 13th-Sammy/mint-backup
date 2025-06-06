#include<iostream>
using namespace std;

int fib(int N)
{
    if (N<=1)
        return N;
    
    int last = fib(N-1);
    int slast = fib(N-2);
    
    return last + slast;
}

int main()
{
    int N;
    cout << "Enter fib count\n";
    cin >> N;
    cout << fib(N) << endl;
    return 0;
}