
N=int(input())
que=list(map(int, input().split()))
que= sorted(que)

result=[]
count=-1
for i in range(N//2):
    if N%2==0:
        result.append(que[i]+que[-i-1])
    else:
        result.append(que[i]+que[-i-2])
if N%2==1:
    result.append(que[-1])
m=max(result)
print(m)
