#include<iostream>
#include<string>
#include<unordered_map>

int main()
{
    using namespace std;

    string a="add";
    string b="egc";

    unordered_map<char, int> mapAB, mapBA;
    int flag=0;

    if(a.length()!=b.length())
        flag=1;

    for (int i=0; i<a.length(); i++)
    {
        char cA=a[i], cB=b[i];
 
        if(mapAB.find(cA)!=mapAB.end() && mapAB[cA]!=cB)
            flag=1;
        if(mapBA.find(cB)!=mapBA.end() && mapBA[cB]!=cA)
            flag=1;

        mapAB[cA]=cB;
        mapBA[cB]=cA;
    }

    if(flag==0)
        cout << "Isomorphic\n";
    else    
        cout << "Not Isomorphic\n";

    return 0;
}