N=int(input())
dist=[]
price=[]
dist=list(map(int, input().split()))
price=list(map(int, input().split()))

result=0
min=0
for i in range(N-1):
    if price[min] > price[i]:
        min=i
    result+=dist[i]*price[min]

print(result)



