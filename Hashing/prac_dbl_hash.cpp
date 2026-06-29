#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
#define mii map<int, int>
#define llu unsigned long long
#define lld long long
int R = 5;
bool isPrime(lld n)
{
    if (n < 2)
        return false;
    for (lld i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int nextPrime(lld n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

void place(vi t, int key, int N)
{
    for (int i = 0; i < N; i++)
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
    int N = 7, cnt = 0;
    vi t(N, -1);
    for (int i = 0; i < k; i++)
    {
        int key;
        cin >> key;
        if ((cnt + 1) * 10 >= N * 7)
        {
            int newN = nextPrime(N * 2);
            vi nt(newN, -1);
            for (int j = 0; j < N; i++)
            {
                if (t[j] != -1)
                {
                    place(nt, t[j], newN);
                }
                t = nt;
                N = newN;
            }
        }
        place(t, key, N);
        cnt++;
    }
    

    return 0;
}