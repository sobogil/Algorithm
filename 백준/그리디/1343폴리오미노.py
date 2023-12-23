import sys
input=sys.stdin.readline

str=input()

str= str.replace("XXXX", "AAAA")
str= str.replace("XX","BB")

if "X" in str:
    print(-1)
else:
    print(str)
