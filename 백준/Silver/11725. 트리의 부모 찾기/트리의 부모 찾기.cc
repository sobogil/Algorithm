#include<bits/stdc++.h>
using namespace std;

int n,a,b;
vector<int> adj[100001];
int p[100001];
int visited[100001];

void bfs(int x){
    visited[x] = 1;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int cur = q.front();q.pop();
        for(int next : adj[cur]){
            if(!visited[next]){
                visited[next] = 1;
                p[next] = cur;
                q.push(next);
            }
        }
    }
}

int main(){
    cin >>n;
    for(int i=0;i<n-1;i++){
        cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);

    for(int i=2;i<=n;i++){
        cout << p[i]<<'\n';
    }
}