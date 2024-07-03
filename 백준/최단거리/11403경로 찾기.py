def floyd_warshall():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                graph[i][j] = min(graph[i][k]+graph[k][j],graph[i][j])
                if graph[i][j]>1 and graph[i][j]!=INF:
                    graph[i][j]=1
INF = float('inf')

n= int(input())
graph=[]
for i in range(n):
    graph.append(list(map(int, input().split())))
for i in range(n):
    for j in range(n):
        if graph[i][j]==0:
            graph[i][j]=INF

floyd_warshall()
for i in range(n):
    for j in range(n):
        if graph[i][j]==INF:
            graph[i][j]=0

for i in graph:
    print(" ".join(map(str,i)))