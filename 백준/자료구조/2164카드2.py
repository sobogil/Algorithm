N= int(input())
ag=[]
for i in range(N):
    ag.append(i+1)

for i in range(N-1):
    ag.pop(0)
    count=ag[0]
    for j in range(len(ag)-1):
        ag[j]=ag[j+1]
    ag[-1]=count

print(ag)