#include<iostream>
#include<string>
using namespace std;

int value(char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

int main()
{
    string roman="LVI";

    int num=0;
    for(int i=0; i<=roman.length(); i++)
    {
        int val=value(roman[i]);
        if(val<value(roman[i+1]));
            num=num-val;
        else    
            num=num+val;
    }   
    cout << num << '\n';

    return 0;
}