# 술자로 이루어진 문자열을 받아 수 하나하나 곱하거나 더해서 최댓값만들기

data = input()
result = int(data[0])

for i in range(1, len(data)):
    num = int(data[i])
    if result<=1 or i<=1 :
        result+=num
    else:
        result*=num
    
print(result)