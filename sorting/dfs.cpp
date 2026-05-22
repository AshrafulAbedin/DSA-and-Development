#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
#define mii map <int,int>
#define llu unsigned long long 
#define lld long long 

vi graph[100];
bool vis[100];

void dfs(int node)
{
    vis[node] = true;
    cout<< node <<'\n';

    for (auto neighbour : graph[node])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour);
        }
        
    }
    
}

int main(void)
{
    int n = 5;

    graph[0]={1,2};
    graph[1]={0,3,4};
    graph[2]={0};
    graph[3]={1};
    graph[4]={1};

    dfs(0);

    return 0;
}