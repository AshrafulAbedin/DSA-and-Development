#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
#define MAX 100

vi graph[MAX];
vb vis(MAX, false);

void addEdge(int u, int v, bool dir = false)
{
    graph[u].push_back(v);
    if (!dir)
    {
        graph[v].push_back(u);
    }
}

void dfs(int src)
{
    vis[src] = true;
    cout << src << " ";
    for (int neighbour : graph[src])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour);
        }
    }
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
    dfs(1);
    return 0;
}