#모험가의 공포도가n이면 모험가는 n명 이상이서 그룹을짜야한다
#그룹의 최댓값?

n = int(input())
data = list(map(int,input().split()))
data.sort()

result = 0
count = 0

for i in data:
    count += 1
    if count>=i:
        result += 1
        count = 0

print(result)
