#include<bits/stdc++.h>
using namespace std;


int n,m,c;
vector<pair<int,int>> adj[50005];

int dist[50005];

void dik(int st){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[st] = 0;
    pq.push({0,st});
    while(pq.size()){
        int cur = pq.top().second;
        int v = pq.top().first;
        // cout << cur;
        pq.pop();
        if(v != dist[cur]) continue;

        for(auto p : adj[cur]){
            int nx = p.first;
            int val = p.second;
            if(dist[nx] > dist[cur] + val){
                dist[nx] = dist[cur] + val;
                pq.push({dist[cur]+val, nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    const int INF = 987654321;
    fill(dist,dist + n+1,INF);

    dik(1);

    cout << dist[n];
}