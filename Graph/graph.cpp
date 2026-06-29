#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAX = 100;

vi adj[MAX];

void addEdge(int u, int v, bool directed = false)
{
    adj[u].push_back(v);

    if (!directed)
    {
        adj[v].push_back(u);
    }
}

void display(int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";

        for (int j = 0; j < (int)adj[i].size(); j++)
        {
            if (j > 0)
                cout << " -> ";

            cout << adj[i][j];
        }

        cout << '\n';
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        addEdge(u, v); 
    }

    cout << "\nAdjacency List:\n";
    display(V);

    return 0;
}