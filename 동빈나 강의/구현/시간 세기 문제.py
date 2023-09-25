#3이 포합되는 시간 세기 00시 00분 00초
# 24시간 =86400초

n = int(input())
result = 0

for i in range(n+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i)+str(j)+str(k): #문자열로 해서 13같은 경우도 해결할 수 있게 해준다
                result +=1

print(result)