n=int(input())
array=list(map(int,input().split()))
d=[0]*100

d[0]=array[0]
d[1]=max(array[0],array[1])
for i in range(2, n):
    d[i]=max(d[i-1],d[i-2]+array[i])

print(d[n-1])

#인접하면 안되는 문제에 대해서는 이전 값이 포함 됐으면 
#이전값이 안됐으면 포함 되고 추가하는 형식으로 만든다