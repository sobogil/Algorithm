#include<bits/stdc++.h>
using namespace std;

int n,q,k,v,visited[5005];
vector<pair<int,int>> adj[5005];
int bfs(int u){
    visited[u] = 1;
    queue<pair<int,int>> qe;
    qe.push({u,987654321});
    int cnt =0;
    while(qe.size()){
        int x = qe.front().first;
        int val = qe.front().second; qe.pop();

        for(auto p : adj[x]){
            if(visited[p.first])continue;
            if(min(p.second,val)>=k){
                cnt++;
                qe.push({p.first,min(p.second,val)});
                visited[p.first] = 1;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> n>>q;

    for(int i=0;i<n-1;i++){

        int a,b,c;
        cin >> a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    while(q--){
        cin >> k>>v;
        int ret = bfs(v);
        cout << ret<<'\n';
        memset(visited,0,sizeof(visited));
    }
}