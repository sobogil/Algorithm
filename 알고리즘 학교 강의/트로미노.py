def check(x,y,size):        # 정사각형을 쪼깬 후 안에 구멍이 있는지 확인하는 함수
    for nx in range(x,x+size):
        for ny in range(y,y+size):
            if result[nx][ny] != 0:
                return False
    return True
 
 
def divide_and_fill(x,y,size):  # 트로미노 함수
    global numbers  
    numbers += 1    # 채워질 수
    next_size = size//2 
    input_position = [[x+next_size-1,y+next_size-1],[x+next_size,y+next_size-1],[x+next_size-1,y+next_size],[x+next_size,y+next_size]]  #처음 x,y에 0,0을 넣어 4조각으로 자를 수 있게 좌표를 잡는다.
    for ind,val in enumerate([[x,y],[x+next_size,y],[x,y+next_size],[x+next_size,y+next_size]]): #탐색을 시작할 좌표를 잡는다.
        sx,sy = val #구간의 좌표를 넣는다
        input_x,input_y = input_position[ind] # 탐색할 점의 좌표를 넣는다
        if check(sx,sy,next_size):  #구간에서 0의 값이 나온다면 number의 값을 넣어준다
            result[input_x][input_y] = numbers
 
    if size == 2: #사이즈가 2즉 k=1이면 종료
        return
    divide_and_fill(x,y,next_size) #왼쪽위 구간 탐색
    divide_and_fill(x+next_size,y,next_size) #왼쪽 아래 구간 탐색
    divide_and_fill(x,y+next_size,next_size) #오른쪽위 구간 탐색
    divide_and_fill(x+next_size,y+next_size,next_size) # 오른쪽 아래 구간 탐색
#즉 간단하게 설명하자면 divide_and_fill함수는 x,y를 기준으로 (x,y),(x+1,y),(x,y+1),(x+1,y+1)을 순서대로 탐색해 0이 나오면 수를 넣어주는 방식으로
#(x,y),(x+1,y),(x,y+1),(x+1,y+1)밖에 탐색을 못하므로 0,0으로 시작을 해버리면 각각 구간의 x,y가 왼쪽위 점이 되므로 전부 탐색 가능하게 해주는 함수다. 
 
 
 
k= int(input())
N = 2**k
input_x,input_y = map(int,input().split())
x = input_y-1  #일반 행렬과 x, y의 위치가 반대로 나오는 문제이므로 입력값의 xy를 바꿔준다.
y = input_x-1
result = [[0 for _ in range(N)] for _ in range(N)]
result[x][y] = -1
 
numbers = 0
divide_and_fill(0,0,N) #0,0으로 시작해서 구간을 나누고 시작한다.
for row in result:
    print(*row)