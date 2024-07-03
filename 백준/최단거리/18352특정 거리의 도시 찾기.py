import heapq
import sys

f = sys.stdin.readline
INF = int(1e9)

N, M, K, X = map(int, f().split()) 

graph = [[]for i in range(N+1)]
distances = [INF]*(N+1)

for i in range(M):
    a, b= map(int, f().split())
    graph[a].append((b, 1))

def dijkstra(start):
    q = [(0, start)]
    distances[start]=0
    while q:
        dist, node = heapq.heappop(q)
        if dist > distances[node]:
            continue
        for i in graph[node]:
            cost = dist + i[1]
            if cost < distances[i[0]]:
                distances[i[0]]=cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(X)
result = []
for i in range(1, N+1):
    if distances[i] == K: result.append(i)

if len(result) == 0: print(-1)
else:
    for i in result: print(i, end='\n')