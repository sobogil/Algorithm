#include<bits/stdc++.h>
using namespace std;

int n,mx;
vector<pair<int,int>> adj[10001];
int visited[10001];

int dfs(int  x){
    visited[x] = 1;
    int ret = 0;
    for(auto p : adj[x]){
        int nx = p.first;
        int val = p.second;
        if(!visited[nx]){
            ret = max(ret, dfs(nx) + val);
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++){
        mx = max(mx,dfs(i));
        memset(visited,0,sizeof(visited));
    }
    cout << mx;
}