import sys
input = sys.stdin.readline

count=0
bingo = []

for i in range(5):
    bingo.append(list(map(int, input().strip().split())))

list1 = []

for i in range(5):
    list1.append(list(map(int, input().split())))
list2 = [item for sublist in list1 for item in sublist]


row=[]
col=[]
cross=[]
#빙고 한칸  채우는 함수
def checkOne(tempBingo, tempList1):
    for i in range(5):
        for j in range(5):
            if(tempBingo[i][j]==tempList1):
                bingo[i][j]=0
                break
#가로 빙고
def rowBingo(tempBingo, rowIndex):
    flag=True
    for i in range(len(row)):
        if row[i]==rowIndex:
            flag=False
    if flag==True:
        result = 0
        global count
        for i in range(5):
            if(tempBingo[rowIndex][i]==0):
                result+=1
        if(result==5):
            row.append(rowIndex)
            count+=1

#세로 빙고
def columeBingo(tempBingo, colIndex):
    flag=True
    for i in range(len(col)):
        if col[i]==colIndex:
            flag=False
    if flag==True:
        result = 0
        global count
        for i in range(5):
            if(tempBingo[i][colIndex]==0):
                result+=1
        if(result==5):
            col.append(colIndex)
            count+=1

#대각선 빙고
def crossBingo(tempBingo):
    flag=True
    for i in range(len(cross)):
        if cross[i]==-1:
            flag=False
    if flag==True:
        result = 0
        global count
        for i in range(5):
            if(tempBingo[i][i]==0):
                result+=1
        if(result==5):
            cross.append(-1)
            count+=1
            
    flag=True
    for i in range(len(cross)):
        if cross[i]==-2:
            flag=False
    if flag==True:
        result = 0
        for i in range(5):
            if(tempBingo[4-i][i]==0):
                result+=1
        if(result==5):
            cross.append(-2)
            count+=1


num=0
while(count<3):
    num+=1
    checkOne(bingo,list2[num-1])
    print(num) 
    for i in range(5):
        rowBingo(bingo, i)
    for i in range(5):
        columeBingo(bingo, i)
    crossBingo(bingo)

print(num)    