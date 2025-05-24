#include<bits/stdc++.h>
using namespace std;

int n,m, a[101];
int dist[101];
int go(int s,int cnt){
    dist[s] = 1;
    queue<pair<int,int>> q;
    q.push({s,0});
    while(q.size()){
        tie(s,cnt)= q.front();q.pop();

        if(s == 100) return cnt;
        for(int i=1;i<=6;i++){
            int nx = s + i;
            if(nx > 100) continue;
            if(a[nx]) nx = a[nx];
            if(!dist[nx]){
                dist[nx] = 1;
                q.push({nx,cnt+1});
            }
        }

    }
    return -1;
}

int main(){
    cin >> n>>m;
    for(int i=0;i<n+m;i++){
        int a1,b;
        cin >> a1>>b;
        a[a1] = b;
    }
    cout << go(1,0);
}