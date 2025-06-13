#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s = "lapalincnilabc";
    int left = 0, maxLen = 0, ansLeft = 0; // Initialize ansLeft to 0
    
    for(int right = 0; right < s.length(); right++)
    {
        string temp = s.substr(left, right - left + 1);
        string reversed = temp;
        reverse(reversed.begin(), reversed.end());
        
        if(temp == reversed) // Current substring is a palindrome
        {
            if(right - left + 1 > maxLen)
            {
                maxLen = right - left + 1;
                ansLeft = left;
            }
        }
        else // Not a palindrome, move left pointer
        {
            left = right;
        }
    }
    
    if(maxLen > 0)
        cout << s.substr(ansLeft, maxLen) << endl;
    else
        cout << "No palindrome found" << endl;
    
    return 0;
}