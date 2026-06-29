#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int R = 5;

bool isprime(long long x)
{
    if (x < 2)
        return false;
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int nextPrime(int n)
{
    while (!isprime(n))
    {
        n++;
    }
    return n;
}

void place(vi &t, int key, int N)
{
    for (int i = 0; ; i++)
    {
        int h1 = key % N;
        int h2 = R - (key % R);
        int pos = (h1 + i * h2) % N;
        if (t[pos] == -1)
        {
            t[pos] = key;
            return;
        }
    }
}

int main(void)
{
    int k;
    cin >> k;
    int N = 7;
    int cnt = 0;
    vi t(N, -1);

    for (int x = 0; x < k; x++)
    {
        int key;
        cin >> key;

        // load factor check BEFORE inserting (avoid float: *10 >= *7)
        if ((cnt + 1) * 10 >= N * 7)
        {
            int newN = nextPrime(N * 2);
            vector<int> nt(newN, -1);
            for (int j = 0; j < N; j++)
                if (t[j] != -1)
                    place(nt, t[j], newN);
            t = nt;
            N = newN;
        }
        place(t, key, N);
        cnt++;
    }

    cout << "Final Capacity: " << N << "\n";
    for (int i = 0; i < N; i++)
        if (t[i] != -1)
            cout << "Index " << i << ": " << t[i] << "\n";
    return 0;
}