#include<iostream>
#include<string>
#include<algorithm>

int main()
{
    using namespace std;

    string s="lapalincnilabc";

    int left=0, flag=0, maxLen=0, ansLeft;
    for(int right=0; right<s.length(); right++)
    {
        if(flag==1)
        {
            maxLen=max(maxLen, right-left);
            ansLeft=left;
            left=right;
            flag=0;
        }

        if(right>=left)
        {
            string temp=s.substr(left, right-left+1);
            reverse(temp.begin(), temp.end());
            if((s.substr(left, right-left+1))==temp)
                flag==1;
        }

    }
    cout << s.substr(ansLeft, maxLen);
    
    return 0;
}