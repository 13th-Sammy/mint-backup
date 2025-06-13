#include<iostream>
#include<string>

int main()
{
    using namespace std;

    int num=56;

    int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string romanNum="";
    for(int i=0; i<13; i++)
    {
        while(num>=values[i])
        {
            num-=values[i];
            romanNum+=symbol[i];
        }
    }
    cout << romanNum << '\n';

    return 0;
}