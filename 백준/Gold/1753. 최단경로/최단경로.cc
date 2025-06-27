#include<bits/stdc++.h>
using namespace std;

int n,m,st;
vector<pair<int,int>> adj[20002];
int dist[20002];
const int INF = 987654321;
void dik(int s){
    fill(dist,dist+n+1,INF);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(pq.size()){
        int cur = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(cur != dist[v])continue;
        for(auto &[nx,w] : adj[v]){
            if(dist[nx] > w + dist[v]){
                dist[nx] = w + dist[v];
                pq.push({dist[nx], nx});
            }
        }
    }
}
int main(){
    cin >>n>>m;
    cin >> st;
    while(m--){
        int a,b,c;
        cin >>a>>b>>c;
        adj[a].push_back({b,c});
        // adj[b].push_back({a,c})
    }

    dik(st);

    for(int i=1;i<=n;i++){
        if(dist[i]==INF)cout << "INF"<<'\n';
        else cout << dist[i]<<'\n';
    }
}