#include<bits/stdc++.h>
using namespace std;

int n,m;
int visited[202];
vector<int> adj[202];
int k;
void bfs(int x){
    visited[x] = 1;
    queue<int> q;   
    q.push(x);
    while(q.size()){
        int cur = q.front();q.pop();
        for(auto p : adj[cur]){
            if(visited[p])continue;
            visited[p] = 1;
            q.push(p);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> k;
            if(k==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i=0;i<m;i++){
        cin >> k;

        if(i!=0){
            if(visited[k]==0){
                cout << "NO";return 0;
            }else{
                memset(visited,0,sizeof(visited));
            }
        }
        bfs(k);
    }
    cout << "YES";
}