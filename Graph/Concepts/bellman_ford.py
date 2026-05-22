import math

def bellman_ford(graph, n, src):
    dist = [math.inf] * (n + 1)
    dist[src] = 0

    for _ in range(n - 1):
        for u in range(1, n + 1):
            for v, w in graph[u]:
                if dist[u] != math.inf and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

    # negative cycle detection
    for u in range(1, n + 1):
        for v, w in graph[u]:
            if dist[u] != math.inf and dist[u] + w < dist[v]:
                return None  # negative cycle exists

    return dist


n, m = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

src = int(input())

dist = bellman_ford(graph, n, src)

if dist is None:
    print("Negative cycle detected")
else:
    for i in range(1, n + 1):
        print(f"dist[{i}] = {dist[i]}")
