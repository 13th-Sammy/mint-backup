#include<iostream>
#include<string>

int main()
{
    using namespace std;

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

    return 0;
}

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
    }
}