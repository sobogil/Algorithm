import sys
input= sys.stdin.readline

result=0
n=int(input())
while True:
    if n%5==0:
        result+=n//5
        break
    else:
        result+=1
        n-=2
    
    if n<0:
        break

if n<0:
    print(-1)
else:
    print(result)
