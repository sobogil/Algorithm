def quickSort(x):       #quicksort 을 이용하였다
    if len(x) <= 1:     #리스트길이가 1이하면 종료한다
        return x
    pivot = x[len(x)//2]    #pivot값을 x리스트의 중간 인덱스의 값으로 사용한다
    left,right,equal =[],[],[]  #pivot값을 중심으로 오른쪽, 왼쪽, 중앙 리스트를 만든다
    for a in x:
        if a < pivot:
            left.append(a)
        elif a > pivot:
            right.append(a)
        else:
            equal.append(a)
    return quickSort(left) + equal + quickSort(right)   #재귀함수를 이용해 길이가 1이하일때까지 실행

n = int(input()) #n을 입력 받는다
data = [] # 입력받을 데이터의 리스트를 만든다
for i in range(n):  #n번 만큼 데이터를 리스트에 넣어준다
    data.append(int(input()))

list = quickSort(data) #미리만든 quicksort()로 만든 리스트를 새로운 리스트에 넣어준다

for i in range(n):  #리스트 값을 출력한다
    print(list[i])
