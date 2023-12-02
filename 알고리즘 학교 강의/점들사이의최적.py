def allPair( D, n):  #최소거리 찾는 알고리즘
    for k in range(n):
        for i in range(n):
            if(i==k): #k일때 
                continue
            for j in range(n):
                if(j==k or j==i): #k또는 i일때
                    continue
                D[i][j]=min(D[i][k]+D[k][j],D[i][j]) #각각 최소거리를 구한다



n= int(input())
D=[]
for i in range(n):
    D.append(list(map(int,input().split())))
allPair(D, n)
for i in range(n):
    for j in range(n):
        print(D[i][j], end=' ')
    print()