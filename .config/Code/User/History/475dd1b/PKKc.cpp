#include<iostream>
#include<string>

int main()
{
    using namespace std;

    string s="lapalincnilabc";
    string backup=s;

    int left=0, flag=0, maxLen=0, ansLeft;
    for(int right=0; right<s.length(); right++)
    {
        if(flag==1)
        {
            maxLen=max(maxLen, right-left+1);
            ansLeft=left;
            left=right;
            flag=0;
        }

        int l=left, r=right;
        while(l<r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
        if((backup.substr(left, right-left+1))==s.substr(left, right-left+1))
            flag==1;

    }
    cout << backup.substr(ansLeft, maxLen-1);
    
    return 0;
}