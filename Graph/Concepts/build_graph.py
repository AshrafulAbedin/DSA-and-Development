#Adj list

n,m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    u,v,w = map(int, input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))


# 𝐢𝐦𝐩𝐨𝐫𝐭 𝐬𝐲𝐬
# 𝐝𝐚𝐭𝐚 = 𝐬𝐲𝐬.𝐬𝐭𝐝𝐢𝐧.𝐫𝐞𝐚𝐝().𝐬𝐭𝐫𝐢𝐩().𝐬𝐩𝐥𝐢𝐭()

# 𝐧 = 𝐢𝐧𝐭(𝐝𝐚𝐭𝐚[0])
# 𝐦 = 𝐢𝐧𝐭(𝐝𝐚𝐭𝐚[1])

# 𝐠𝐫𝐚𝐩𝐡 = {𝐢: [] 𝐟𝐨𝐫 𝐢 𝐢𝐧 𝐫𝐚𝐧𝐠𝐞(1,𝐧+1)}

# 𝐢𝐝𝐱 = 2

# 𝐟𝐨𝐫 _ 𝐢𝐧 𝐫𝐚𝐧𝐠𝐞(𝐦):
#     𝐮 = 𝐢𝐧𝐭(𝐝𝐚𝐭𝐚[𝐢𝐝𝐱])
#     𝐯 = 𝐢𝐧𝐭(𝐝𝐚𝐭𝐚[𝐢𝐝𝐱+1])
#     𝐢𝐝𝐱+=2
    
#     𝐠𝐫𝐚𝐩𝐡[𝐮].𝐚𝐩𝐩𝐞𝐧𝐝(𝐯)
#     𝐠𝐫𝐚𝐩𝐡[𝐯].𝐚𝐩𝐩𝐞𝐧𝐝(𝐮)
    
# 𝐩𝐫𝐢𝐧𝐭(𝐠𝐫𝐚𝐩𝐡)

# from collections import defaultdict

# graph = defaultdict(list)

# m = int(input())

# for _ in range(m):
#     u,v,w = map(int, input().split())
#     graph[u].append((v,w))
#     graph[v].append((u,w))
    
print(graph)

