#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
#define mii map<int, int>
#define llu unsigned long long
#define lld long long

int lin(int keys[], int M, int N)
{
    vi t(N, -1);
    int total = 0;
    for (int i = 0; i < M; i++)
    {
        int k = keys[i], j = 0;
        while (t[(k % N + j) % N] != -1)
        {
            total++, j++;
        }
        t[(k % N + j) % N] = k;
    }
    return total;
}
int quad(int keys[], int M, int N)
{
    vi t(N, -1);
    int total = 0;
    for (int i = 0; i < M; i++)
    {
        int k = keys[i], j = 0;
        while (t[(k % N + j * j) % N] != -1)
        {
            total++, j++;
        }
        t[(k % N + j * j) % N] = k;
    }
    return total;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    int keys[1005];
    for (int i = 0; i < M; i++)
    {
        cin >> keys[i];
    }

    cout<< lin(keys, M, N) << '\n';
    cout<< quad(keys, M, N) <<'\n';

    return 0;
}