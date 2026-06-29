#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string text, string pat)
{
    int n = text.size();
    int m = pat.size();

    if (m > n)
    {
        cout << "Pattern not found\n";
        return;
    }

    const int d = 256;     // Number of characters
    const int q = 101;     // Prime number

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int pHash = 0; // Pattern hash
    int tHash = 0; // Text window hash

    // Initial hash calculation
    for (int i = 0; i < m; i++)
    {
        pHash = (d * pHash + pat[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

    bool found = false;

    for (int i = 0; i <= n - m; i++)
    {
        // If hashes match, check characters one by one
        if (pHash == tHash)
        {
            bool match = true;

            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                cout << "Pattern found at index " << i << '\n';
                found = true;
            }
        }

        // Calculate hash for next window
        if (i < n - m)
        {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % q;

            if (tHash < 0)
                tHash += q;
        }
    }

    if (!found)
        cout << "Pattern not found\n";
}

int main()
{
    string text, pat;
    cin >> text >> pat;

    rabinKarp(text, pat);

    return 0;
}