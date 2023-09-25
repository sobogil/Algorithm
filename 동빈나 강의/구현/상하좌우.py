n = int(input())
x,y=1,1
data = input().split()

dx = [0,0,-1,1]
dy = [-1,1,0,0]
move=['L', 'R', 'U', 'D']
nx, ny = 0,0
for plan in data:
    for i in range(len(move)):
        if plan==move[i]:
            nx = x + dx[i]
            ny = y + dy[i]
        if nx < 1 or ny < 1 or nx > n or ny > n:
            continue
        x,y =nx , ny

print(x,y)

