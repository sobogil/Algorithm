N= int(input())


#스택을 이용하여 괄호가 (이면 append
#괄호가 )일때 안에 (이면 pop 아무것도 없으면 NO출력
result=[]
for i in range(N):
    arg = input()
    stack=[]
    for j in arg:
        if j=="(":
            stack.append(j)
        elif j==")":
            if stack:
                stack.pop()
            else:
                print("NO")
                break
    else:
        if not stack:
            print("YES")
        else:
            print("NO")

