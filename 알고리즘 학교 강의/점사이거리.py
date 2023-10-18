import math

#리스트 P를 받아 그 안의 점들 각각의 거리를 구하는 함수
def small(P, n):    
    min = float('inf')
    for i in range(n):
        for j in range(i + 1, n):
            if dist(P[i], P[j]) < min:
                min = dist(P[i], P[j])
    return min

#두점 사이의 거리를 구하는 함수
def dist(p1, p2):
    dis= math.sqrt((p1[0] - p2[0]) **2 +(p1[1] - p2[1]) **2)
    return round(dis, 6) #소수점 6번째 자리로 리턴

#가운데를 기준으로 각각 x의 거리가 d사이인 점들을 받은 리스트를 y값끼리의 거리가 d를 넘지않는 값만 탐색하는 함수
def inside_dist(inside, size, d):
    min = d
    for i in range(size):
        j = i + 1
        while j < size and (inside[j][1] - inside[i][1]) < min: #여기서 y값을 비교한다
            min=dist(inside[i], inside[j])
            j += 1
    return min

#d의 최솟값을 구하는 함수 재귀함수형태
def closestPair(x,n):
    if n<=3:
        return small(x,n) # 점 3개가 되면 리턴
    else:
        result=[]
        sortedx_data = sorted(x, key=lambda x: x[0]) # x값을 기준으로 정렬
        mid = n // 2
        midPoint = x[mid]
        CPl = sortedx_data[:mid] #좌측 값들을 넣어줌
        CPr = sortedx_data[mid:] #우측 값들을 넣어줌
        dl = closestPair(CPl, mid) #재귀함수 호출로 좌측에서 가장 작은 값 리턴
        dr = closestPair(CPr, n - mid) #재귀함수 호출로 우측에서 가장 작은 값 리턴

        if(dl>dr):
            d=dr
        else:
            d=dl

        for i in sortedx_data:
            if(i[0]<=midPoint[0]+d and i[0] >= midPoint[0]-d): #플마 d사이의 값들을 리스트에 넣어준다
                result.append(i)    
        sortedy_data = sorted(result, key=lambda x: x[1]) #y값을 기준으로 정렬
        arg=inside_dist(sortedy_data, len(sortedy_data), d)
        if(d>arg):
            d=arg
        return d
        
n = int(input())
list1=[]
for i in range(n):
    point = input()
    x, y = map(float, point.replace(',', ' ').split())
    list1.append((x, y))
print(closestPair(list1,n))