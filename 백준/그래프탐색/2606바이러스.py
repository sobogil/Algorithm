from collections import deque
n = int(input())
k = int(input())
graph = [[]for i in range(n+1)]
visited=[0]*(n+1)

for i in range(k):
    a, b = map(int, input().split())
    graph[a]+=[b]
    graph[b]+=[a]

visited[1]=1
Q=deque([1])
while Q:
    c=Q.popleft()
    for ty in graph[c]:
        if visited[ty]==0:
            Q.append(ty)
            visited[ty]=1
print(sum(visited)-1)