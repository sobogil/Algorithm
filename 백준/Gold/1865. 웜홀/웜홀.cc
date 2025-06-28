#include<bits/stdc++.h>
using namespace std;

int t,n,m,w;
vector<pair<int,int>> adj[505];
int dist[505];
const int INF =987654321;
int flag;
void bellman(){
    fill(dist,dist+n+1,0);
    dist[1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(auto p : adj[j]){
                int v = p.first;
                int ret = p.second;
                if(dist[j]!=INF && dist[v] > dist[j] + ret){
                    dist[v] = dist[j] + ret;
                    if(i==n)flag = 1;
                }
            }
        }
    }
}

int main(){
    cin >>t;
    while(t--){
        cin >>n>>m>>w;
        int a,b,c;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for(int i=0;i<m;i++){
            cin >>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        for(int i=0;i<w;i++){
            cin >>a>>b>>c;
            adj[a].push_back({b,-c});
        }
        bellman();
        if(flag)cout << "YES"<<'\n';
        else{ cout << "NO"<<'\n';}
        flag=0;
    }
}