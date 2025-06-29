#include<bits/stdc++.h>
using namespace std;

int t,n,k,en;
int delay[1001];
int deg[1001],dp[1001];
vector<int> adj[1001];
void go(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) {
            q.push(i);
            dp[i] = delay[i];    
        }
    }
    while(q.size()){
        int cur = q.front();q.pop();
        for(int nx : adj[cur]){
            dp[nx] = max(dp[cur]+ delay[nx] , dp[nx]);
            if(--deg[nx] ==0){
                q.push(nx);
            }
        }
    }

    cout << dp[en]<<'\n';
}

int main(){
    cin >>t;
    while(t--){
        cin >>n>>k;
        for(int i=1;i<=n;i++){
            cin >> delay[i];
            adj[i].clear();
            deg[i]=0;
            dp[i]=0;
        }
        while(k--){
            int a,b;
            cin >> a>>b;
            adj[a].push_back(b);
            deg[b]++;
        }
        cin >>en;
        go();
    }
}