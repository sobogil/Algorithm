N, K= map(int,input().split())

stack=[]
for i in range(1,N+1):
    stack.append(i)
result=[]
pi=0
for i in range(N):
    pi += K-1
    if pi>=len(stack):
        pi%=len(stack)
    result.append(str(stack[pi]))
    stack.pop(pi)

print("<",", ".join(result),">", sep="")