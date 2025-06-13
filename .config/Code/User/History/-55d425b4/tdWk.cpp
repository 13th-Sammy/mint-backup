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
            int k=0;
            while(k<num.length());
            {
                int d = (int)num[k];
                int n = 10*n+d;
                if (n>max)
                    max=n;
                k++; 
            }
        }
    }
    cout << max;

    return 0;
}