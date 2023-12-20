from collections import deque
import sys

N=int(input())
que=deque(enumerate(map(int, sys.stdin.readline().split())))
re=[]
while que:
    idx, paper=que.popleft()
    re.append(idx+1)
    if paper >0:
        que.rotate(-(paper-1))
    elif paper <0:
        que.rotate(-paper)

print(" ".join(map(str,re)))

