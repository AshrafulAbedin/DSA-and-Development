#include <bits/stdc++.h>
using namespace std;
#define MAX 10
typedef vector<int> vi;
typedef vector<bool> vb;

vi graph[MAX];

/*
==================difference================
vector<int> a(5);   //CAN DIRECTLY ASSIGN VALUES
a = [0, 0, 0, 0, 0]

vector<int> a[5]; // USE PUSH_BACK(X)
a[0] -> vector
a[1] -> vector
a[2] -> vector
a[3] -> vector
a[4] -> vector
*/

void addEdge(int u, int v, bool dir = false)
{
    graph[u].push_back(v);
    if (!dir)
    {
        graph[v].push_back(u);
    }
}
void bfs(int src, int n)
{
    queue<int> q;
    vb visited((n + 1), false);
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i : graph[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << '\n';
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    bfs(1, n);
    return 0;
}