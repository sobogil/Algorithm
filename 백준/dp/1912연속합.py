n=int(input())
A=list(map(int,input().split()))

d = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for j in range(i,n):
        d[i][j]=sum(A[i:j])
max_value = max(max(row) for row in d)
print(max_value)