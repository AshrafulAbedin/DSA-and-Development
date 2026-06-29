n,m = map(int, input(). split())

vis = [False] * (n+1)
def dfs(src, n):
    vis[src] = True
    print(src, end = " ")
    
    for neighbour in graph[src]:
        if not vis[neighbour]:
            dfs(neighbour, n)
        

graph = [[]for _ in range(n+1)]
for _ in range(m):
    u,v = map(int, input(). split())
    graph[u].append(v)
    graph[v].append(u)
    
dfs(1,n)