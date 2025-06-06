#include <iostream>
using namespace std;

void print1toN(int i, int N)
{
    if (i > N)
        return;
    cout << i << endl;
    print1toN(++i, N);

    /*i++ causes infinite recursion -
    current value i used FIRST to call 
    and THEN increment but that is UNUSED
    ++i or just i+1 works.*/
}

int main()
{
    int N;
    cout << "Enter N\n"; cin >> N;
    cout << endl;
    print1toN(1, N);
}