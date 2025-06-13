#include<iostream>
#include<string>

int main()
{
    using namespace std;

    string str[] = {"flowers" , "flow" , "fly", "flight" };
    int n=sizeof(str)/sizeof(str[0]);

    string prefix=str[0];
    // compare prefix with every other string 
    // as long as first elements match
    for(int i=1; i<n; i++)
    {
        int j=0;
        while (j<str[i].length() && j<prefix.length() && prefix[j]==str[i][j])
            j++;
        prefix=prefix.substr(0,j);
    }
    cout << prefix;

    return 0;
}