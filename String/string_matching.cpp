#include <bits/stdc++.h>
using namespace std;

void naive(string str1, string str2)
{
    int n, m;
    n = str1.size();
    m = str2.size();
    if (m > n)
    {
        cout << "Invalid" << '\n';
        return ;
    }
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
            if (j == m-1)
            {
                cout << "Match Found char at " << i << '\n';
            }
        }
    }
    return ;
}

int main(void)
{
    string str1, str2;
    cout << "Enter the sentence: " << '\n';
    getline(cin, str1);
    cout << "Enter the word to match: " << '\n';
    getline(cin, str2);

    naive(str1, str2);
    return 0;
}