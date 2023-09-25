data = input()
count = 0
list = []

for i in data:
    if i.isalpha():
        list.append(i)
    else:
        count += int(i)

list.sort()

if count != 0:
    list.append(str(count))

print(''.join(list))
