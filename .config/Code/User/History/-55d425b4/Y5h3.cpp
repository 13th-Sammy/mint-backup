#include<iostream>
#include<string>

int main()
{
    using namespace std;

    string s="53478";
    
    // Brute Force -
    int max=-1;
    for(int i=0; i<s.length(); i++)
    {
        string num="";
        for(int j=i; j<s.length(); j++)
        {
            num=num+s[j];
            int n=stoi(num);
            if (n%2!=0 && n>max)
                max=n;
        }
    }
    cout << max;

    return 0;
}