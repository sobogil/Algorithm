def fibo(n):
    #n까지 만들 피보나치 수열을 만들어준다
    people=[1,1] #피보나치 수열을 저장할 리스트를 만든다
    while people[-1]<n: #n보다 값이 커지면 종료, 인덱스에 -1을 넣어 리스트의 마지막 값을 이용
        people.append(people[-2]+people[-1]) #리스트에 추가
    l1=[] #치킨 수 확인 리스트
    sum=0 #인원 수 더한 변수
    #이제 피보나치 수열에서 제켄도르프 정리를 이용해 성립되는 피보나치 수들을 
    #sum에 더해가고 그 때마다 치킨값을 l1에 넣어주며 n과 동일하게 될 때 까지 수행
    while True: 
        if(sum+people[-1]<n): #n보다 작을 경우 
            sum+=people[-1] #sum에 리스트 마지막 값을 넣어준다
            l1.append(people[-2]) #치킨 수는 그 전 리스트의 값이므로 -2를 써서 l1에 추가 한다
            people.pop(-1) #sum에 담겼으므로 삭제해준다
        elif (sum+people[-1]==n): #n과 같을 경우 
            l1.append(people[-2]) #해당하는 인원의 치킨을 리스트에추가 후
            return l1 # 모든 치킨의 수를 리스트에 담아 리턴
        else:
            people.pop(-1) #n을 오버해버리므로 과감하게 삭제

n=int(input()) #문자를 정수형으로 받는다
data =fibo(n) #fibo()함수에서 리턴된 리스트 값을 data넣는다
print(sum(data)) #리스트안에 있는 수를 전부 더해 print한다
