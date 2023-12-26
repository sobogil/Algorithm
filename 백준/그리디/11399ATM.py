N=int(input())
num=[]
num=(list(map(int, input().split())))
print(num)
num=sorted(num)

result=0
ca=0
for i in num:
    ca+=result+i
    result+=i
print(ca)