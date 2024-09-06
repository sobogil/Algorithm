n , m = map(int, input().split())
tr = list(map(int, input().split()))

start, end = 0, max(tr)

while start<=end:
    mid = (start + end)//2
    getTree = 0
    for i in tr:
        if mid <= i:
            getTree += i - mid
            
    if getTree >= m:
            start = mid + 1
    else:
            end = mid - 1
print(end)
    