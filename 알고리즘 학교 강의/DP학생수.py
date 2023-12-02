
INF = 10**9 * 3  
mirae = [[[-1 for _ in range(2)] for _ in range(1001)] for _ in range(1001)]
pre = [0 for _ in range(1001)]
 
# D_P함수는 현재 위치를 l,r로 받아와 l과 r이 각각 1과 n이 됐을 때 종료하는 함수. p는 ture 또는 false구분 하는 값.
def D_P(l, r, p):
    if l==1 and r==n: # l과 r이 각각 1과 n이 됐을 때 종료한다
        return 0
    if mirae[l][r][p] != -1:  # 현재 들어있는 값인 -1이 아니면 종료하게끔
        return mirae[l][r][p]
    total = s - (pre[r] - pre[l-1]) # 내가 지나간 방의 불은 꺼져있으므로 전체 전력양에서 지나간 방들의 전력의 합을 빼준다
    mirae[l][r][p] = INF #큰 값을 넣어 만약 처음 스타트 위치가 왼쪽 끝이나 오른쪽 끝일 때 min이 잘 수행 될 수 있게 한다.
    if l>1: # l을 1로 만드는게 목표이며 1보다 크면 계속 수행해서 l을 1씩 깎는다
        mirae[l][r][p] = D_P(l-1, r, 0) + total * ((idx[r] if p else idx[l]) - idx[l-1]) # D_P(l-1, r, 0)는 왼쪽으로 한칸 옮겼을때 전력양을 파악해주고, 
            # ((idx[r] if p else idx[l]) - idx[l-1])에서 p를 이용해 p가 0이면 왼쪽으로 1이면 오른쪽으로 이동하는 전력양을 구해 더한다. 
    if r<n: # r을 n으로 만들 때까지 실행
        mirae[l][r][p] = min(mirae[l][r][p],D_P(l, r+1, 1) + total * (idx[r+1] - (idx[r] if p else idx[l]))) 
        #이미 왼쪽으로 간 경우의 값과 오른쪽으로 갔을 때의 값 중 어느것이 더 작은지 비교하여 더 작은 값을 넣어준다
    return mirae[l][r][p]
 
idx = [0]  # 거리를 넣어줄 리스트
cost = [0]  # 전력비용을 넣어줄 리스트
n, m = map(int, input().split())
for i in range(n):
    x, y = map(int, input().split())
    idx.append(x)
    cost.append(y)
for i in range(1, n+1):
    pre[i] = pre[i-1] + cost[i]  # pre리스트에 비용을 합쳐서 넣어준다.
 
s = pre[n] # s는 모든 비용의 합
print(D_P(m,m,0))