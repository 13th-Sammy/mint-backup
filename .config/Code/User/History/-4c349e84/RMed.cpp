#include<iostream>
#include<string>
#include<unordered_map>

int main()
{
    using namespace std;

    string s1="abbbcde";
    string s2="cbdecba";
    
    int flag=0;
    unordered_map<char, int> hash;
    if(s1.length()!=s2.length())
        flag=1;

    for(int i=0; i<s1.length(); i++)
    {
        hash[s1[i]]++;
        hash[s2[i]]--;
    }

    // OR, hash1[s1[i]]++, hash2[s2[i]]++;
    // if hash1==hash2, true
    // It compares every key with their frequencies

    for(int i=0; i<s1.length(); i++)
    {
        if(hash[s1[i]]!=0)
            flag=1;
    }

    if(flag==0)
        cout << "Anagram\n";
    else    
        cout << "Not Anagram\n";

    return 0;
}