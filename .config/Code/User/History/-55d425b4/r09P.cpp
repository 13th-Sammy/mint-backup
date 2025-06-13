#include<iostream>
#include<string>

int main()
{
    using namespace std;

    string s="53478";
    
    for(int i=0; i<s.length(); i++)
    {
        string num="";
        for(int j=i; j<s.length(); j++)
        {
            num=num+s[j];
            cout << num << "\n";
        }
    }

    return 0;
}