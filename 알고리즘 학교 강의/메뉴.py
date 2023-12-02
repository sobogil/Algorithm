# 힙 조건을 만족하는 판단하는 함수
def down_heap(arr, n, i):
    largest = i  #부모 인덱스
    left_child = 2 * i + 1 #왼쪽 자식인덱스
    right_child = 2 * i + 2 #오른쪽 자식 인덱스

    # 왼쪽 자식이 더 큰 경우
    if left_child < n and arr[left_child] > arr[largest]:
        largest = left_child

    # 오른쪽 자식이 더 큰 경우
    if right_child < n and arr[right_child] > arr[largest]:
        largest = right_child

    # 최댓값이 현재 노드(i)가 아니라면 교환하고 다운 힙을 재귀적으로 수행
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        down_heap(arr, n, largest)

#힙 소트 알고리즘
def heap_sort(arr):
    n = len(arr)

    #중간 부분부터 첫 인덱스까지 다운힙을 돌려주어 부모보다 큰 자식이 없게 해준다
    #즉 새로 생긴 메뉴의 가격을 먼저 다운힙으로 제 위치에 가게 해준다.
    for i in range(n // 2 - 1, -1, -1):
        down_heap(arr, n, i)
    
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # 루트 노드와 마지막 노드 교환 후
        down_heap(arr, i, 0) # 크기를 n-1부터 0까지 하나씩 줄여가며 다운힙을 돌려준다.

#최저 메뉴 두개를 더하고 가격을 새로 만드는 함수
#arr[0]과 arr[1]을 이용해 나온 값을 arr[0]을 pop시키고 arr[0]에 넣어준다
def sum_two_value(arr):
    k=arr[0]+arr[1]*2
    arr.pop(0) # 크기한개 제거
    arr[0]=k

data=[]
result=[] #메뉴 가격이 들어갈 리스트

for i in range(1):
    data.append(list(map(int,input().split())))

for i in data[0]:
    result.append(i)

M=int(input())

heap_sort(result) #한번 힙 소트
count=0 # 카운트 할 수

while result[0]<M: #메뉴 가격이 M보다 작을때 까지
    sum_two_value(result) #두 메뉴 합치고 크기 한개 줄어듬
    heap_sort(result) # 힙 소트
    count +=1

print(count)