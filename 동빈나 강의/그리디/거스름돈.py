#거스름 돈을 거슬러 줄 때 화폐단위가 전부 배수의 형태를 띌 때 이와 같은
#풀이가 가능하다.

n=1260
count = 0 

#큰단위의 화폐부터 차례대로 확인하기
array = [500,100,50,10]

for coin in array:
    count +=n // coin #해당 화폐로 거슬러 줄 수 있는 동전의 개수 세기
    n%= coin

print(count)