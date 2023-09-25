#문제 설명
#어떠한 수 이 1이 될때까지 두 과정 중 하나를 반복 수행 
#2번 과정은 n이 k로 나누어 떨어질 때만 선택 가능
#1. n에서 1을 뺍니다.
#n을 k로 나눕니다.

n , k = map(int,input().split())

result = 0 

while True :
    target = (n//k)*k
    result += n-target
    n=target

    if n<k:
        break

    result+=1
    n//=k

result+=(n-1) #n이 1이 될때까지 빼므로 n-1회만큼 시행횟수가 증가한다
print(result)