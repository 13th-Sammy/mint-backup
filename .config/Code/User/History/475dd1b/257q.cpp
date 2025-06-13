#include<iostream>
#include<string>
#include<algorithm>

int main()
{
    using namespace std;

    string s="lapalincnilabc";

    int left=0, flag=0, maxLen=0, ansLeft=0;
    for(int right=0; right<s.length(); right++)
    {
        string temp=s.substr(left, right-left+1);
        string rev=temp;
        reverse(rev.begin(), rev.end());

        if(rev==temp)
        {
            if(maxLen>right-left+1)
            {
                maxLen=right-left+1;
                ansLeft=left;
                left=right+1;
            }
        }
    }
    cout << s.substr(ansLeft, maxLen);
    
    return 0;
}