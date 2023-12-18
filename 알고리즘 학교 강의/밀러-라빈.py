import random
def miller_rabin_test(n,b,s,d):
    b0= pow(b,d,n) #임의의 b를 d제곱해서 n으로 나눈 나머지를 b0에 넣는다
    if b0 == 1 or b0 == n-1: #b0가 1또는 -1이면 소수(페르마의 소정리)
        return 1
    else:
        for i in range(s):  #b0가 다른 수라면 -1이 됐을 때만 소수 이므로 계속 실행
            if b0==n-1:
                return 1
            b0=pow(b0,2,n)
        return 0
    
def is_prime(n):
    s=0
    if n<2 or not n&1: #짝수 이거나 소수가 아닐 경우
        return 0
    if n==2:    #2는 소수
        return 1
    d=(n-1)     #d=n-1
    while d%2==0:   #d를 2로 나누어 지지 않을때까지 실행
        s=s+1   #s는 0의 갯수
        d>>=1
    for i in range(0,25):
        b = random.randrange(2,n-1) #b의 범위를 2와 n-1로 두고 그중에 랜덤으로 수를 가져옴
        test=miller_rabin_test(n,b,s,d) #밀러-라빈시행
        if test==0:
            return 0
    return 1

P= int(input())
print(is_prime(P))