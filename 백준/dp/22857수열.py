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

#시간복잡도 만족 불가

n, k = map(int, input().split())
s = [0] + list(map(int, input().split()))
dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1, n+1):
    s[i] %= 2
    for j in range(k+1):
        if s[i] == 0: #짝수일 때
            dp[i][j] = dp[i-1][j] + 1
        if j != 0 and s[i]: #홀수일 때 
            dp[i][j] = dp[i-1][j-1]
            
result = []
for i in dp:
    result.append(i[k])

print(max(result))