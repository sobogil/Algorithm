#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a,b,c, visited[10001],st,en,mx,ret;
vector<pair<ll,ll>> adj[10001];
bool bfs(ll mid){
    queue<ll> q;
    visited[st] =1;
    q.push(st);
    while(q.size()){
        ll cur = q.front();q.pop();
        if(cur == en)return true;
        for(auto &p: adj[cur]){
            if(mid > p.second || visited[p.first])continue;
            q.push(p.first);
            visited[p.first]=1;
        }
    }
    return false;
}
int main(){
    cin >>n>>m;
    for(int i=0;i<m;i++){
        cin >>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        mx=max(mx,c);
    }

    cin >> st >> en;

    ll le =1,ri=mx;
    while(le<=ri){
        ll mid = (le+ri)/2;
        if(bfs(mid)){
            ret = mid;
            le = mid +1;
        }else{
            ri = mid-1;
        }
        memset(visited,0,sizeof(visited));
    }
    cout <<ret;
}