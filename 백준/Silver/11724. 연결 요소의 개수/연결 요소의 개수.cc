#include<bits/stdc++.h>
using namespace std;

int n,m,visited[1004],ret;
vector<int> adj[1004];

void bfs(int here){
    queue<int> q;
    q.push(here);
    visited[here] =1;
    while(q.size()){
        int x = q.front();q.pop();
        for(auto &there : adj[x]){
            if(visited[there])continue;
            visited[there] = 1;
            q.push(there);
        }
    }
}
int main(){
    cin >>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        bfs(i);
        ret++;
    }
    cout << ret;
}