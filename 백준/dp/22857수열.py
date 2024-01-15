n, k = map(int, input().split())
num=list(map(int, input().split()))

del num[k]
d=[1]*(n//2)
result=[]
count=0
for j in range(1,len(num),2):
    result.append(num[j])
for i in range(1,len(result)):
    for j in range(i):
        if result[j]<result[i]:
            d[i]=max(d[i],d[j]+1)
print(max(d))

