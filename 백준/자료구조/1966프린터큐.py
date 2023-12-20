from collections import deque
T=int(input())
for i in range(T):
    N, K=map(int, input().split())
    num=deque()
    for i in range(N):
        num.append(i)
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





