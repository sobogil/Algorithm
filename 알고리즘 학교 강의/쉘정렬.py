def shell_sort(arr):
    gap = n // 2  # 초기 간격 설정

    while gap > 0: # gab=1이 될 때까지 실행
        for i in range(gap, n):
            temp = arr[i] #temp에 값 저장
            j = i 
            while j >= gap and arr[j - gap] > temp: # j>=gab이고 arr[j-gab]의 값이 기존 temp값보다 클 때 위치 변화
                arr[j] = arr[j - gap] #위치를 바꿔줌
                j -= gap # j-=gab을 해주고 j>=gab이면 계속 실행 비교 할 수 있도록 실행
            arr[j] = temp #변한 위치에 temp를 넣어준다

        gap //= 2  # 간격을 반으로 줄임

n= int(input())
A=[]
for i in range(n):
    A.append(int(input()))

shell_sort(A)

for data in A:
    print(data)