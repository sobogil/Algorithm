# setCover 함수는 그리디 알고리즘을 이용해서 원하는 값을 얻는 함수
def setCover(u,f,k):
    c=[]
    lll=[]
    while len(u)!=0:
        max=find_much(f,u) #가장 큰 부분 집합을 찾는다
        arg=find_c(k,max) #해당 집합의 위치 즉 지원자의 번호를 찾는다.
        c.append(arg)
        for i in range(len(max)):
            if(u.count(max[i])==True):
                u.remove(max[i]) 
        f.remove(max)
    lll= bubble_sort(c)
    return lll
# 가장 큰 부분집합을 찾는 함수
def find_much(f,u):
    max_subset=[]
    result=[]
    if len(u)==1: #만약 u가 한개밖에 남지 않았다면 원소가 작은 순부터 파악한다
        target_element = u[0]
        result = find_list_with_element(f, target_element) #파악하는 함수
    else: #아닐 경우 가장 원소의 갯수가 많은 집합을 찾는다
        max_subset.append(max(f, key=len))
        for sublist in max_subset:
            for item in sublist:
                result.append(item)
    return result
# u가 한개일때 원소가 작은 수부터 확인해서 가장 원소가 작은 집합을 리턴
def find_list_with_element(matrix, target_element):
    for row in sorted(matrix, key=len):
        if target_element in row:
            return row
    return None
# 지원자의 번호를 리턴하는 함수
def find_c(k, max):
    value=0
    j=0
    for i in range(len(k)):
        if k[j]==max:
            value=j+1
            break
        j+=1
    return value
#버블 sort를 구현
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

N , M = map(int,input().split()) 
u=[]
for i in range(M):
    u.append(i+1)
f=[]
for i in range(N):
    f.append(list(map(int,input().split())))
k=[] #k리스트는 지원자의 번호를 확인할 때 f의 리스트가 remove되므로 f를 대신해 파악할 용도로 만들어 둔다
for i in range(len(f)):
    k.append(f[i])
for i in setCover(u, f,k):
    print(i, end= " ")