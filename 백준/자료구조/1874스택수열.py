count=1
temp=True
stack=[]
op=[]
#count를 이용해 num만큼 전부 stack에 넣어
#pop이 가능할 경우에만 pop을 이용해 출력하고 
#만약 불가능한 수열이면 temp를 이용해 구분한다 
N=int(input())
for i in range(N):
    num = int(input())
    
    while count <=num:
        stack.append(count)
        op.append("+")
        count +=1

    if stack[-1]==num:
        stack.pop()
        op.append("-")
    else:
        temp=False
        break

if temp==False:
    print("NO")
else:
    for i in op:
        print(i)    