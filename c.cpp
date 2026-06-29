#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
#define mii map <int,int>
#define llu unsigned long long 
#define lld long long 

const int MAXV = 100005;
vector<int> adj[MAXV];
bool visited[MAXV];
void addEdge(int u, int v, bool directed = false) {
    adj[u].push_back(v);
    if (!directed) adj[v].push_back(u);
}
void bfs(int s) {
    queue<int> q; visited[s] = true; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        sort(adj[u].begin(), adj[u].end());
        for (int v : adj[u]) if (!visited[v]) { visited[v] = true; q.push(v); }
    }
}
void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    sort(adj[u].begin(), adj[u].end());
    for (int v : adj[u]) if (!visited[v]) dfs(v);
}

int main(void)
{
    
    return 0;
}