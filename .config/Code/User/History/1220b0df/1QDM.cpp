#include<iostream>
#include<string>
#include<algorithm>

int main()
{
    using namespace std;

    string s="Hi I like gloopers";

    int left=0;
    for (int right=0; right<=s.length(); right++)
    {
        if (s[right]==' ' || right==s.length())
        {
            reverse(s.begin()+left,s.begin()+right);
            left=right+1;
        }
    }
    cout << s;
    
    return 0;
}