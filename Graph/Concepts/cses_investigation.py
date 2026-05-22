import heapq
INF = float('inf')

def Dijkstra(graph, n, src):
    dist = [INF]*(n+1)
    dist[src] = 0
    parent = [-1]*(n+1)
    
    pq = [(0,src)]
    
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v,w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                heapq.heappush(pq, (dist[v],v))
    return dist, parent



def get_path(parent, target):
    path=[]
    while target != -1:
        path.append(target)
        target = parent[target]
    return path[::-1]



n,m = map(int, input().split())

graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))
    # directed
dist, parent = Dijkstra(graph, n, 1)

print(min(dist[:]))
print(count(min(dist[:])))
