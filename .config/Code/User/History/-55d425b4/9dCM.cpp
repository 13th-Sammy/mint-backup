#include<iostream>
#include<string>

int main()
{
    using namespace std;

    string s="53478";
    
    int max=-1;
    for(int i=0; i<s.length(); i++)
    {
        string num="";
        for(int j=i; j<s.length(); j++)
        {
            num=num+s[j];
            int k=0, n=0, d;
            while(k<num.length())
            {
                d = (int)num[k];
                n = 10*n+d;
                if (n>max)
                    max=n;
                k++; 
            }
        }
    }
    cout << max;

    return 0;
}