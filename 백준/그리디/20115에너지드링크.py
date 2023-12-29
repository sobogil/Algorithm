from collections import deque

N=int(input())
que=list(map(int, input().split()))

que=sorted(que)
que=deque(que)



for i in range(N-1):
    a=que.popleft()
    que[-1]+=a/2
print(que[-1])