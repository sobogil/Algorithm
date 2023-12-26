N=int(input())
num=[int(input()) for i in range(N)]
num=sorted(num, reverse=True)
a=(int)(len(num)/3)

for i in range(a):
    num[3*i+2]=0
result=sum(num)
print(result)
