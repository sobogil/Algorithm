n=int(input())

dp=[0,1]
for i in range(2,n+1):
    min_L=4
    j=1
    while (j**2)<=i:
        min_L=min(min_L,dp[i-j**2])
        j+=1
    dp.append(min_L+1)
print(dp[n])