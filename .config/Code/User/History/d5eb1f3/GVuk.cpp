#include<iostream>
#include<queue>
#include<unordered_map>

char firstNonRepeatChar(std::string s)
{
    std::queue<char> q;
    std::unordered_map<char, int> freq;

    for(int i=0; i<s.length(); i++)
    {
        freq[s[i]]++;
        q.push(s[i]);
    }

    while(!q.empty() && freq[q.front()]>1)
        q.pop();
    
    if(q.empty())
        return '-1';
    else    
        return q.front();
}

int main()
{
    using namespace std;

    string s="aabcc";
    std::cout << firstNonRepeatChar(s) << '\n';
    
    return 0;
}