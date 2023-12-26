N=int(input())
num=[]
num=(list(map(int, input().split())))
num=sorted(num)

result=0
for i in range(1,N+1):
    result+=sum(num[0:i])
    
print(result)