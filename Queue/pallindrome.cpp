#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    deque<char> dq;
    for (char c : s)
    {
        if (c != ' ')
        {
            dq.push_back(tolower(c));
        }
    }

    while (dq.size() > 1)
    {
        if (dq.front() != dq.back())
        {
            return false;
        }
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}

int main(void)
{
    string s;
    getline(cin, s);

    cout << (isPalindrome(s) ? "YES" : "NO") << '\n';
    return 0;
}