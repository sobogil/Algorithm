import math
#거리 계산 함수
def dist(p1,p2):
    return math.sqrt((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)
#N, M받아온다
N , M = map(int, input().split())
result=[]
for i in range(N):
    result.append(list(map(int,input().split())))

#center 만들기 (경찰관 좌표)
center=[]
center.append(result[0])
del result[0]  #(경찰관 좌표를 지워줌)

for i in range(M-1):  #M-1번 실행
    min_value=0  # 가장 긴 거리 비교할 때 쓸 변수
    for j in range(N-i-1):  # 경찰 좌표 추가하면 하나씩 횟수를 줄여주기위해 N-i-1
        max_value=float("inf") # 가장 짧은 값 찾을 때 비교할 변수
        for k in range(len(center)): # 경찰관 좌표들끼리 거리를 비교해 가장 짧은 값을 찾는다
            D=dist(center[k],result[j])
            if D!=0:
                D=min(D,max_value) #한 점에 대해 경찰관들의 거리가 가장 짧은 길이 구하기
                max_value=D
        if D>min_value and D!=0: #가장 짧은 거리끼리 비교해서 그중에서 가장 긴 길이가 되도록 코드를 짬
            min_value=D
            count=j
    center.append(result[count]) # 가장 긴 길이가 되는 지첨의 좌표를 넣어줌
    del result[count]

G=[]
for i in center:
    print(" ".join(map(str,i)))





   