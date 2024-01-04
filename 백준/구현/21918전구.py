n, m = map(int, input().split())
s=list(map(int, input().split()))
for i in range(m):
    a, b, c=map(int, input().split())
    if a==1:
        s[b-1]=c
    if a==2:
        for i in range(b-1,c):
            s[i]^=1
    if a==3:
        for i in range(b-1,c):
            s[i]=0
    if a==4:
        for i in range(b-1,c):
            s[i]=1
sr=list(map(str,s))
print(" ".join(sr))
