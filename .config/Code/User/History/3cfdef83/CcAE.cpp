#include <iostream>
using namespace std;

void factorial(int N)
{
    if(N == 0)
    {
        N = N * 1;
        cout << N << endl;
        return ;
    }
    N = N*factorial(N-1);
}

int main()
{
    int N;
    cout << "Factorial of what number ?\n";
    cin >> N;
    factorial(N);
}