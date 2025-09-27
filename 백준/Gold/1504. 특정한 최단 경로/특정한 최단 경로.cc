#include<bits/stdc++.h>
using namespace std;

int n,e;
int dist[801];
vector<pair<int,int>> adj[801];
int INF =987654321;

void dik(int st){
    fill(dist,dist+n+1,INF);
    dist[st] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,st});
    while(!pq.empty()){
        int cur = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(dist[v] != cur) continue;
        for(auto &[nx,val] : adj[v]){
            if(dist[nx] > dist[v] + val){
                dist[nx] = dist[v] + val;
                pq.push({dist[nx], nx});
            }
        }
    }
}

int main(){
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int v1,v2;
    cin >> v1 >> v2;

    int path1 = 0, path2 = 0;

    dik(1);
    if(dist[v1] == INF) path1 = INF; else path1 += dist[v1];
    dik(v1);
    if(dist[v2] == INF) path1 = INF; else path1 += dist[v2];
    dik(v2);
    if(dist[n] == INF) path1 = INF; else path1 += dist[n];

    dik(1);
    if(dist[v2] == INF) path2 = INF; else path2 += dist[v2];
    dik(v2);
    if(dist[v1] == INF) path2 = INF; else path2 += dist[v1];
    dik(v1);
    if(dist[n] == INF) path2 = INF; else path2 += dist[n];

    int ans = min(path1, path2);
    if(ans >= INF) cout << -1; 
    else cout << ans;
}