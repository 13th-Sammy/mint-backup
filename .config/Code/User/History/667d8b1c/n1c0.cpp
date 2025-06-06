#include<iostream>
using namespace std;

bool ifPal(int i, string &s)
{
    if (i >= s.length()/2)
        return true;
    if (s[i] != s[s.length()-i-1])
        return false;
    return ifPal(i+1, s);
}

int main()
{
    string s;
    cout << "Enter string\n";
    cin >> s;
    bool ans = ifPal(0, s);
    if (ans==true)
        cout << "Palindrome\n";
    else    
        cout << "Not Palindrome\n";
    return 0;
}