from collections import deque

def bfs(src, n):
    vis = [False]*(n+1)
    q = deque()
    vis[src] = True
    q.append(src)
    
    while q:
        node = q.popleft()
        print(node, end =" ")
        for neighbour in graph[node]:
            if not vis[neighbour]:
                vis[neighbour] = True
                q.append(neighbour)
                
            
    

n,m = map(int, input(). split())
graph = [[]for _ in range(n+1)]
for _ in range(m):
    u,v = map(int, input(). split())
    graph[u].append(v)
    graph[v].append(u)
    
bfs(1,n)