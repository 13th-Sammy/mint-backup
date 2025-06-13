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

    for(int right=0; right<s.length(); right++)
    {
        char current=s[right];

        if(charIndex.find(current) != charIndex.end() && charIndex[current]>=left)
            left=charIndex[current]+1;
        
        charIndex[current]=right;

        maxLen=max(maxLen, right-left+1);
    }
    cout << maxLen;
    return 0;
}