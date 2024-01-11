n=int(input())
num=list(map(int, input().split()))
dp=[1]*n
count=0
for i in range(1,n):
    for j in range(i):
        if num[i]>num[j]:
            dp[i]=max(dp[i],dp[j]+1)
print(max(dp))