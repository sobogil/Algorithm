
N= int(input())
eval=list(input())
num=[int(input()) for i in range(N)]

a=[]

for i in eval:
    if i.isalpha():
        a.append(num[ord(i)-65])
    else:
        k=a.pop()
        result=a.pop()
        if i=='*':
            result*=k
        elif i=='-':
            result-=k
        elif i=='+':
            result+=k
        elif i=='/':
            result/=k

        a.append(result)
print('%.2f' %a[-1])
