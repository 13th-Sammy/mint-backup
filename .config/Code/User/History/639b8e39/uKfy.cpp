#include<iostream>
using namespace std;

void printN(int n, int cnt)
{
    cout << n << endl;
    cnt --;
    if (cnt == 0)csJ Kc SAKJsanklcs L CAMlacMLOadv KL A MM 
        return;
    printN(n, cnt);
}

int main()
{
    int n, cnt;
    
    cout << "Enter number\n"; cin >> n;
    cout << "Enter count\n"; cin >> cnt;
    cout << endl;
    printN(n, cnt);
    
    return 0;
}