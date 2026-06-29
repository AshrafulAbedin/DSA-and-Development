#include <bits/stdc++.h>
using namespace std;

int naive(string str1, string str2)
{
    int n,m;
    n = str1.size();
    m = str2.size();
    if (m>n)
    {
        cout<< "Invalid" <<'\n';
        return -1;
    }
    
}

int main(void)
{
    string str1, str2;
    cout<< "Enter the sentence: " <<'\n';
    getline(cin,str1);
    cout<< "Enter the word to match: " <<'\n';
    getline(cin,str2);

    return 0;
}