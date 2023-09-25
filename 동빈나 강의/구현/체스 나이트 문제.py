#나이트가 8x8좌표에서 이동할 수 있는 경우의 수 구하기

data= input()
row = int(data[1])
column = int(ord(data[0]))-int(ord('a'))+1

move = [(-2,-1), (-2,1), (2,-1), (2,1), 
        (-1,-2), (-1,2), (1,-2), (1,2)]

result = 0
for moves in move:
    next_row= row + moves[0]
    next_column= column + moves[1]
    if next_column>=1 and next_row>=1 and next_row<=8 and next_column<=8:
        result +=1
print(result)