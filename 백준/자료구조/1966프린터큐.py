from collections import deque
import sys
T=int(input())
for i in range(T):
    N, K=map(int, input().split())
    num=deque(list(map(int, sys.stdin.readline().split())))
    count=0
    while num:
        best=max(num)
        a=num.popleft()
        K-=1

        if a==best:
            count+=1
            if K<0:
                print(count)
                break
        else:
            num.append(a)
            if K<0:
                K=len(num)-1





