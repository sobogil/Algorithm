N=int(input())
num=[int(input()) for i in range(N)]

num=sorted(num)
n=len(num)
for i in range(n):
    num[i]*=n-i
print(max(num))