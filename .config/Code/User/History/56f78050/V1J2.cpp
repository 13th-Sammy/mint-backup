#include <iostream>
using namespace std;
int main()
{
    double a,b; int ch, end;
    while (true)
    {
        cout << "Enter 2 numbers" << endl;
        cin >> a;
        cin >> b;
        cout << "Enter -\n1 for +\n2 for -\n3 for x\n4 for /\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << "Result of + is " << (a+b) << endl;
                break;
            }
            case 2:
            {
                if(a>b)
                    cout << "Result of - is " << (a-b) << endl;
                else
                    cout << "Result of - is " << (b-a) << endl;
                break;
            }
            case 3:
            {
                cout << "Result of x is " << (a*b) << endl;
                break;
            }
            case 4:
            {
                if(a>b)
                    cout << "Result of / is " << (a/b) << endl;
                else
                    cout << "Result of / is " << (b/a) << endl;
                break;
            }    
            default:
                cout << "Wrong Choice\n";
        }
        cout << "Press 0 to quit, anything else to continue\n";
        cin >> end;
        if (end == 0)
            break;
    }
    return 0;
}