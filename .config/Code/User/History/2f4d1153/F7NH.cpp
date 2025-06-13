#include<iostream>
#include<string>
#include<unordered_map>

int main()
{
    using namespace std;

    string s="ababbcde";
    
    unordered_map<char, int> charIndex;
    int maxLen=0;
    int left=0;
    int ansLeft;

    // right-left is our array. if character already present
    // in charIndex<char, int> and is inside the window,
    // shift left to go beyond the duplicate character
    // index hash + sliding winoow approach
    for(int right=0; right<s.length(); right++)
    {
        char current=s[right];

        if(charIndex.find(current) != charIndex.end() && charIndex[current]>=left)
            left=max(left,charIndex[current]+1);
        
        charIndex[current]=right;

        if(right-left+1>maxLen)
        {
            maxLen=right-left+1;
            ansLeft=left;
        }
    }
    cout << s.substr(ansLeft, maxLen);
    return 0;
}