import heapq
INF = 10**9
def dijkstra(graph, n, src):
    dist = [INF] * n
    parent = [-1] * n
    dist[src] = 0
    
    pq = [(0,src)] # (dist,node)
    
    while pq:
        d,u = heapq.heappop(pq)
        
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                heapq.heappush(pq, (dist[v],v))
    
    return dist, parent

def get_path(parent, target):
    path = []
    while target != -1:
        path.append(target)
        target = parent[target]
        
    return path [::-1]

n = 5
graph = [[] for _ in range(n)]
graph [0].extend([(1,2),(2,6)])
graph [1].extend([(3,5)])
graph [2].extend([(3,8),(4,3)])
graph [3].extend([(4,1)])

dist, parent = dijkstra(graph, n,0)

print(dist)
print(get_path(parent, 4))